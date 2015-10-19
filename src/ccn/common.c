/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * Copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), a Xerox company.  All Rights Reserved.
 * The content of this file, whole or in part, is subject to licensing terms.
 * If distributing this software, include this License Header Notice in each
 * file and provide the accompanying LICENSE file.
 */
/**
 * @author Alan Walendowski, Computing Science Laboratory, PARC
 * @copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), A Xerox Company. All Rights Reserved.
 */

#include "common.h"

#include <LongBow/runtime.h>

#include <ccnx/common/ccnx_NameSegmentNumber.h>

#include <parc/security/parc_Security.h>
#include <parc/security/parc_PublicKeySignerPkcs12Store.h>
#include <parc/security/parc_IdentityFile.h>

const char *common_DomainPrefix = "lci:/test";
const uint32_t common_ChunkSize = 1200;

PARCIdentity *
common_CreateAndGetIdentity(const char *keystoreName, const char *keystorePassword, const char *subjectName)
{
    parcSecurity_Init();

    unsigned int keyLength = 1024;
    unsigned int validityDays = 30;

    bool success = parcPublicKeySignerPkcs12Store_CreateFile(keystoreName, keystorePassword, subjectName, keyLength, validityDays);
    assertTrue(success,
               "parcPublicKeySignerPkcs12Store_CreateFile('%s', '%s', '%s', %d, %d) failed.",
               keystoreName, keystorePassword, subjectName, keyLength, validityDays);

    PARCIdentityFile *identityFile = parcIdentityFile_Create(keystoreName, keystorePassword);
    PARCIdentity *result = parcIdentity_Create(identityFile, PARCIdentityFileAsPARCIdentity);
    parcIdentityFile_Release(&identityFile);

    parcSecurity_Fini();

    return result;
}

CCNxPortalFactory *
common_SetupPortalFactory(const char *keystoreName, const char *keystorePassword, const char *subjectName)
{
    PARCIdentity *identity = common_CreateAndGetIdentity(keystoreName, keystorePassword, subjectName);
    CCNxPortalFactory *result = ccnxPortalFactory_Create(identity);
    parcIdentity_Release(&identity);

    return result;
}

uint64_t
common_GetChunkNumberFromName(const CCNxName *name)
{
    size_t numberOfSegmentsInName = ccnxName_GetSegmentCount(name);
    CCNxNameSegment *chunkNumberSegment = ccnxName_GetSegment(name, numberOfSegmentsInName - 1);

    assertTrue(ccnxNameSegment_GetType(chunkNumberSegment) == CCNxNameLabelType_CHUNK,
               "Last segment is the wrong type, expected CCNxNameLabelType %02X got %02X",
               CCNxNameLabelType_CHUNK,
               ccnxNameSegment_GetType(chunkNumberSegment)) {
        ccnxName_Display(name, 0); // This executes only if the enclosing assertion fails
    }

    return ccnxNameSegmentNumber_Value(chunkNumberSegment);
}

char *
common_CreateFileNameFromName(const CCNxName *name)
{
    // For the Tutorial, the second to last NameSegment is the filename.
    CCNxNameSegment *fileNameSegment = ccnxName_GetSegment(name, ccnxName_GetSegmentCount(name) - 2); // '-2' because we want the second to last segment

    assertTrue(ccnxNameSegment_GetType(fileNameSegment) == CCNxNameLabelType_NAME,
               "Last segment is the wrong type, expected CCNxNameLabelType %02X got %02X",
               CCNxNameLabelType_NAME,
               ccnxNameSegment_GetType(fileNameSegment)) {
        ccnxName_Display(name, 0); // This executes only if the enclosing assertion fails
    }

    return ccnxNameSegment_ToString(fileNameSegment); // This memory must be freed by the caller.
}
