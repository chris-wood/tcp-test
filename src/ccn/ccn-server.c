/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * Copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), a Xerox company.  All Rights Reserved.
 * The content of this file, whole or in part, is subject to licensing terms.
 * If distributing this software, include this License Header Notice in each
 * file and provide the accompanying LICENSE file.
 */
/**
 * @author Glenn Scott, Alan Walendowski, Computing Science Laboratory, PARC
 * @copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), A Xerox Company. All Rights Reserved.
 */

#include <strings.h>

#include "common.h"
#include "fileio.h"

#include <LongBow/runtime.h>

#include <ccnx/api/ccnx_Portal/ccnx_Portal.h>
#include <ccnx/api/ccnx_Portal/ccnx_PortalRTA.h>

#include <parc/algol/parc_Memory.h>

#include <ccnx/common/ccnx_Name.h>
#include <ccnx/common/ccnx_ContentObject.h>


/**
 * Create a new CCNxPortalFactory instance using a randomly generated identity saved to
 * the specified keystore.
 *
 * @return A new CCNxPortalFactory instance which must eventually be released by calling ccnxPortalFactory_Release().
 */
static CCNxPortalFactory *
_setupServerPortalFactory(void)
{
    const char *keystoreName = "tutorialServer_keystore";
    const char *keystorePassword = "keystore_password";
    const char *subjectName = "tutorialServer";

    return common_SetupPortalFactory(keystoreName, keystorePassword, subjectName);
}

static uint64_t
_getNumberOfChunksRequired(uint64_t dataLength, uint32_t chunkSize)
{
    uint64_t chunks = (dataLength / chunkSize) + (dataLength % chunkSize > 0 ? 1 : 0);
    return (chunks == 0) ? 1 : chunks;
}

static u_int64_t
_getFinalChunkNumberOfFile(const char *filePath, uint32_t chunkSize)
{
    size_t fileSize = fileio_GetFileSize(filePath);
    uint64_t totalNumberOfChunksInFile = _getNumberOfChunksRequired(fileSize, chunkSize);

    // If the file size == 0, the the final chunk number is 0. Else, it's one less
    // than the number of chunks in the file.

    return totalNumberOfChunksInFile > 0 ? (totalNumberOfChunksInFile - 1) : 0;
}

static CCNxContentObject *
_createContentObject(const CCNxName *name, PARCBuffer *payload, uint64_t finalChunkNumber)
{
    // In the call below, we are un-const'ing name for ccnxContentObject_CreateWithDataPayload()
    // but we will not be changing it.
    CCNxContentObject *result = ccnxContentObject_CreateWithDataPayload((CCNxName *) name, payload);
    ccnxContentObject_SetFinalChunkNumber(result, finalChunkNumber);

    return result;
}

static CCNxContentObject *
_createFetchResponse(const CCNxName *name, const char *directoryPath, const char *fileName, uint64_t requestedChunkNumber)
{
    CCNxContentObject *result = NULL;
    uint64_t finalChunkNumber = 0;

    // Combine the directoryPath and fileName into the full path name of the desired file
    size_t filePathBufferSize = strlen(fileName) + strlen(directoryPath) + 2; // +2 for '/' and trailing null.
    char *fullFilePath = parcMemory_Allocate(filePathBufferSize);
    assertNotNull(fullFilePath, "parcMemory_Allocate(%zu) returned NULL", filePathBufferSize);
    snprintf(fullFilePath, filePathBufferSize, "%s/%s", directoryPath, fileName);

    // Make sure the file exists and is accessible before creating a ContentObject response.
    if (fileio_IsFileAvailable(fullFilePath)) {
        // Since the file's length can change (e.g. if it is being written to while we're fetching
        // it), the final chunk number can change between requests for content chunks. So, update
        // it each time this function is called.
        finalChunkNumber = _getFinalChunkNumberOfFile(fullFilePath, common_ChunkSize);

        // Get the actual contents of the specified chunk of the file.
        PARCBuffer *payload = fileio_GetFileChunk(fullFilePath, common_ChunkSize, requestedChunkNumber);

        if (payload != NULL) {
            result = _createContentObject(name, payload, finalChunkNumber);
            parcBuffer_Release(&payload);
        }
    }

    parcMemory_Deallocate((void **) &fullFilePath);

    return result; // Could be NULL if there was no payload
}

static CCNxContentObject *
_createInterestResponse(const CCNxInterest *interest, const CCNxName *domainPrefix, const char *directoryPath)
{
    CCNxName *interestName = ccnxInterest_GetName(interest);

    uint64_t requestedChunkNumber = common_GetChunkNumberFromName(interestName);

    char *fileName = common_CreateFileNameFromName(interestName);
    CCNxContentObject *result = _createFetchResponse(interestName, directoryPath, fileName, requestedChunkNumber);
    parcMemory_Deallocate((void **) &fileName);

    return result;
}

static bool
_receiveAndAnswerInterests(CCNxPortal *portal, const CCNxName *domainPrefix, const char *directoryPath)
{
    bool result = false;
    CCNxMetaMessage *inboundMessage = NULL;

    while ((inboundMessage = ccnxPortal_Receive(portal)) != NULL) {
        if (ccnxMetaMessage_IsInterest(inboundMessage)) {
            CCNxInterest *interest = ccnxMetaMessage_GetInterest(inboundMessage);

            CCNxContentObject *response = _createInterestResponse(interest, domainPrefix, directoryPath);

            // At this point, response has either the requested chunk of the request file/command,
            // or remains NULL.

            if (response != NULL) {
                // We had a response, so send it back through the Portal.
                CCNxMetaMessage *responseMessage = ccnxMetaMessage_CreateFromContentObject(response);

                if (ccnxPortal_Send(portal, responseMessage) == false) {
                    fprintf(stderr, "ccnxPortal_Send failed (error %d). Is the Forwarder running?\n", ccnxPortal_GetError(portal));
                }

                ccnxMetaMessage_Release(&responseMessage);
                ccnxContentObject_Release(&response);

                result = true; // We have received, and responded to, at least one Interest.
            }
        }
        ccnxMetaMessage_Release(&inboundMessage);
    }

    return result;
}

static bool
_serveDirectory(const char *directoryPath)
{
    bool result = false;

    CCNxPortalFactory *factory = _setupServerPortalFactory();

    CCNxPortal *portal =
        ccnxPortalFactory_CreatePortal(factory, ccnxPortalRTA_Message, &ccnxPortalAttributes_Blocking);

    assertNotNull(portal, "Expected a non-null CCNxPortal pointer. Is the Forwarder running?");

    CCNxName *domainPrefix = ccnxName_CreateFromURI(common_DomainPrefix);

    if (ccnxPortal_Listen(portal, domainPrefix)) {
        printf("tutorial_Server: now serving files from %s\n", directoryPath);
        result = _receiveAndAnswerInterests(portal, domainPrefix, directoryPath);
    }

    ccnxPortal_Release(&portal);
    ccnxPortalFactory_Release(&factory);

    return result;
}

int
main(int argc, char *argv[argc])
{
    int status = EXIT_FAILURE;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <Directory>\n", argv[0]);
        exit(1);
    }

    char *directory = argv[1];

    status = (_serveDirectory(directory) ? EXIT_SUCCESS : EXIT_FAILURE);

    exit(status);
}
