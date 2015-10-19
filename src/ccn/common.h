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

#ifndef common_h
#define common_h

#include <stdint.h>

#include <parc/security/parc_Identity.h>

#include <ccnx/common/ccnx_Name.h>

#include <ccnx/api/ccnx_Portal/ccnx_Portal.h>

extern const char *common_DomainPrefix;
extern const uint32_t common_ChunkSize;

/**
 * Creates and returns a new randomly generated Identity, which is required for signing.
 * In a real application, you would actually use a real Identity. The returned instance
 * must eventually be released by calling parcIdentity_Release().
 *
 * @param [in] keystoreName The name of the file to save the new identity.
 * @param [in] keystorePassword The password of the file holding the identity.
 * @param [in] subjectName The name of the owner of the identity.
 *
 *
 * @return A new, randomly generated, PARCIdentity instance.
 */
PARCIdentity *common_CreateAndGetIdentity(const char *keystoreName, const char *keystorePassword, const char *subjectName);

/**
 * Initialize and return a new instance of CCNxPortalFactory. A randomly generated identity is
 * used to initialize the factory. The returned instance must eventually be released by calling
 * ccnxPortalFactory_Release().
 *
 * @param [in] keystoreName The name of the file to save the new identity.
 * @param [in] keystorePassword The password of the file holding the identity.
 * @param [in] subjectName The name of the owner of the identity.
 *
 * @return A new instance of a CCNxPortalFactory initialized with a randomly created identity.
 */
CCNxPortalFactory *common_SetupPortalFactory(const char *keystoreName, const char *keystorePassword, const char *subjectName);

/**
 * Given a CCNxName instance, return the numeric value of the chunk specified by the Name.
 * The chunk number is contained in the final NameSegment of the Name.
 *
 * @param [in] name A CCNxName instance from which to extract the chunk number.
 * @return The chunk number encoded in the supplied CCNxName instance.
 */
uint64_t common_GetChunkNumberFromName(const CCNxName *name);

/**
 * Given a CCNxName instance, structured for this tutorial, return a string representation
 * of the file name in the CCNxName. For the tutorial, this is located in the second to
 * last CCnxNameSegment in the CCNxName. The string returned here must eventually be freed
 * by calling parcMemory_Deallocate().
 *
 * @param [in] name A CCNxName instance from which to extract the filename.
 * @return A C string representation of the filename encoded in the supplied CCNxName instance.
 */
char *common_CreateFileNameFromName(const CCNxName *name);

#endif // common.h
