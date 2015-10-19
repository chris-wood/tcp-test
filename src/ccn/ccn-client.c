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
#include <stdio.h>
#include <strings.h>

#include "common.h"
#include "fileio.h"

#include <LongBow/runtime.h>

#include <ccnx/api/ccnx_Portal/ccnx_Portal.h>
#include <ccnx/api/ccnx_Portal/ccnx_PortalRTA.h>

#include <ccnx/common/ccnx_ContentObject.h>
#include <ccnx/common/ccnx_Interest.h>
#include <ccnx/common/ccnx_Name.h>

#include <parc/algol/parc_Memory.h>
#include <parc/algol/parc_BufferComposer.h>

#include <parc/security/parc_Security.h>
#include <parc/security/parc_IdentityFile.h>
#include <parc/security/parc_PublicKeySignerPkcs12Store.h>

static CCNxPortalFactory *
_setupConsumerPortalFactory(void)
{
    const char *keystoreName = "tutorialClient_keystore";
    const char *keystorePassword = "keystore_password";
    const char *subjectName = "tutorialClient";

    return common_SetupPortalFactory(keystoreName, keystorePassword, subjectName);
}

static bool
_assembleFile(const char *fileName, const PARCBuffer *payload, uint64_t chunkNumber, uint64_t finalChunkNumber)
{
    if (chunkNumber == 0) {
        // If we're the first chunk (chunk #0), then make sure we're starting with an empty file.
        fileio_DeleteFile(fileName);
    }

    // Note that the fileio_AppendFileChunk() function should be replaced with something that keeps
    // an open file pointer instead of repeatedly re-opening it. This method simply opens (possibly creating)
    // the file and appends the specified payload). It is not an efficient implementation.
    fileio_AppendFileChunk(fileName, payload);

    return (chunkNumber == finalChunkNumber); // true, if we just wrote the final chunk
}

static bool
_receiveFileChunk(const char *fileName, const PARCBuffer *payload, uint64_t chunkNumber, uint64_t finalChunkNumber)
{
    bool isComplete = _assembleFile(fileName, payload, chunkNumber, finalChunkNumber);

    if (isComplete) {
        printf("File '%s' has been fully transferred in %ld chunks.\n", fileName, (unsigned long) finalChunkNumber + 1L);
    } else {
        printf("File '%s' has been %04.2f%% transferred.\r", fileName,
               ((float) chunkNumber / (float) finalChunkNumber) * 100.0f);
        fflush(stdout);
    }

    return isComplete;
}

static uint64_t
_receiveContentObject(CCNxContentObject *contentObject, const CCNxName *domainPrefix)
{
    CCNxName *contentName = ccnxContentObject_GetName(contentObject);

    uint64_t chunkNumber = common_GetChunkNumberFromName(contentName);

    // Get the number of the final chunk, as specified by the sender.
    uint64_t finalChunkNumberSpecifiedByServer = ccnxContentObject_GetFinalChunkNumber(contentObject);

    // Process the payload.
    PARCBuffer *payload = ccnxContentObject_GetPayload(contentObject);

    char *fileName = common_CreateFileNameFromName(contentName);
    _receiveFileChunk(fileName, payload, chunkNumber, finalChunkNumberSpecifiedByServer);
    parcMemory_Deallocate((void **) &fileName);

    return (finalChunkNumberSpecifiedByServer - chunkNumber); // number of chunks left to transfer
}

static CCNxInterest *
_createInterest(const char *targetName)
{
    CCNxName *interestName = ccnxName_CreateFromURI(common_DomainPrefix);

    PARCBuffer *targetBuf = parcBuffer_WrapCString((char *) targetName);
    CCNxNameSegment *targetSegment = ccnxNameSegment_CreateTypeValue(CCNxNameLabelType_NAME, targetBuf);
    parcBuffer_Release(&targetBuf);

    ccnxName_Append(interestName, targetSegment);
    ccnxNameSegment_Release(&targetSegment);

    CCNxInterest *result = ccnxInterest_CreateSimple(interestName);
    ccnxName_Release(&interestName);

    return result;
}

static bool
_receiveResponseToIssuedInterest(CCNxPortal *portal, const CCNxName *domainPrefix)
{
    bool isTransferComplete = false;

    while (isTransferComplete == false && ccnxPortal_IsError(portal) == false) {
        CCNxMetaMessage *response = ccnxPortal_Receive(portal);

        if (response != NULL) {
            if (ccnxMetaMessage_IsContentObject(response)) {
                CCNxContentObject *contentObject = ccnxMetaMessage_GetContentObject(response);

                // Receive the content message. This returns the number of blocks remaining
                // in the transfer. If it returns 0, it was the final block of the content
                // and we're done.

                if (_receiveContentObject(contentObject, domainPrefix) == 0) {
                    isTransferComplete = true;
                }
            }
            ccnxMetaMessage_Release(&response);
        }
    }

    return isTransferComplete;
}

static bool
_fetchFile(const char *targetName)
{
    bool result = false;
    CCNxPortalFactory *factory = _setupConsumerPortalFactory();

    CCNxPortal *portal = ccnxPortalFactory_CreatePortal(factory, ccnxPortalRTA_Chunked, &ccnxPortalAttributes_Blocking);

    assertNotNull(portal, "Expected a non-null CCNxPortal pointer.");

    CCNxInterest *interest = _createInterest(targetName);

    CCNxMetaMessage *message = ccnxMetaMessage_CreateFromInterest(interest);
    if (ccnxPortal_Send(portal, message)) {
        CCNxName *domainPrefix = ccnxName_CreateFromURI(common_DomainPrefix);  // e.g. 'lci:/ccnx/tutorial'
        result = _receiveResponseToIssuedInterest(portal, domainPrefix);
        ccnxName_Release(&domainPrefix);
    }

    ccnxMetaMessage_Release(&message);
    ccnxInterest_Release(&interest);
    ccnxPortal_Release(&portal);
    ccnxPortalFactory_Release(&factory);

    return result;
}

int
main(int argc, char *argv[argc])
{
    int status = EXIT_FAILURE;

    if (argc != 2) {
        fprintf(stderr, "usage: %s <File Name>\n", argv[0]);
        exit(1);
    }

    char *fileName = argv[1];

    status = _fetchFile(fileName) ? EXIT_SUCCESS : EXIT_FAILURE;

    exit(status);
}
