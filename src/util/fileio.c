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
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>

#include <LongBow/runtime.h>
#include <parc/algol/parc_Memory.h>
#include <parc/algol/parc_BufferComposer.h>

#include "fileio.h"
#include "common.h"

uint8_t *
fileio_GetFileChunk(const char *fileName, size_t chunkSize, uint64_t chunkNum)
{
    FILE *file = fopen(fileName, "r");

    assertNotNull(file, "Could not open file '%s' - stopping.", fileName);

    // When PARCFileInputStream has a Seek() function, consider using it instead of
    // the following approach.

    // Seek to the location of the desired chunk in the file.
    assertTrue(fseek(file, chunkSize * chunkNum, SEEK_SET) == 0, "Could not seek to desired chunk");

    // If we're here, we were able to seek to the start of the desired chunk

    uint8_t *chunk = (uint8_t *) malloc(chunkSize);

    size_t numberOfBytesNeeded = chunkSize;
    size_t numberOfBytesRead = 0;       // # bytes read in each read.
    size_t totalNumberOfBytesRead = 0;  // Overall # of bytes read

    // Read until we get the required number of bytes.
    size_t position = 0;
    while (numberOfBytesNeeded > 0
           && (numberOfBytesRead = fread((void *) chunk + position, 1, numberOfBytesNeeded, file)) > 0) {
        numberOfBytesNeeded -= numberOfBytesRead;
        position += numberOfBytesRead
        totalNumberOfBytesRead += numberOfBytesRead;
    }

    fclose(file);

    return chunk;
}

size_t
fileio_AppendFileChunk(const char *fileName, const uint8_t *chunk, size_t length)
{
    size_t numBytesWritten = 0;

    FILE *file = fopen(fileName, "a"); // Open for appending. Create if it doesn't exist.

    assertNotNull(file, "Could not open file '%s' - stopping.", fileName);

    numBytesWritten = fwrite((void *) chunk, 1, length, file);

    assertTrue(numBytesWritten == length, "Couldn't write requested chunk to file: %s", fileName);

    fclose(file);

    return numBytesWritten;
}

bool
fileio_IsFileAvailable(const char *filePath)
{
    return (access(filePath, F_OK | R_OK) == 0);
}

size_t
fileio_GetFileSize(const char *filePath)
{
    size_t fileSize = 0;

    FILE *fp = fopen(filePath, "r");

    assertNotNull(fp, "Could not open file '%s' to get size.", filePath);

    if (NULL != fp) {
        fseek(fp, 0, SEEK_END);
        fileSize = ftell(fp);
        fclose(fp);
    }
    return fileSize;
}

PARCBuffer *
fileio_CreateDirectoryListing(const char *directoryName)
{
    DIR *directory = opendir(directoryName);

    assertNotNull(directory, "Couldn't open directory '%s' for reading.", directoryName);

    PARCBufferComposer *directoryListing = parcBufferComposer_Create();

    struct dirent *entry;
    while ((entry = readdir(directory)) != NULL) {
        switch (entry->d_type) {
            case DT_REG: {
                // a regular file

                // We need the full file path to check its size.
                PARCBufferComposer *fullFilePath = parcBufferComposer_Create();
                parcBufferComposer_Format(fullFilePath, "%s/%s", directoryName, entry->d_name);

                PARCBuffer *fileNameBuffer = parcBufferComposer_ProduceBuffer(fullFilePath);
                char *fullFilePathString = parcBuffer_ToString(fileNameBuffer);
                parcBuffer_Release(&fileNameBuffer);

                if (fileio_IsFileAvailable(fullFilePathString)) {
                    parcBufferComposer_Format(directoryListing, "  %s  (%zu bytes)\n",
                                              entry->d_name, fileio_GetFileSize(fullFilePathString));
                }

                parcBufferComposer_Release(&fullFilePath);
                parcMemory_Deallocate((void **) &fullFilePathString);

                break;
            }

            case DT_LNK:
            case DT_DIR:
            default:
                // ignore everything but regular files
                break;
        }
    }

    closedir(directory);

    PARCBuffer *result = parcBufferComposer_ProduceBuffer(directoryListing);
    parcBufferComposer_Release(&directoryListing);

    return result;
}

bool
fileio_DeleteFile(const char *fileName)
{
    // Unlink the file. Return true if succesful, false if not.
    // False could mean the file didn't originally exist.
    return (unlink(fileName) == 0);
}
