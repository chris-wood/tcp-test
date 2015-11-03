/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 * Copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), a Xerox company.  All Rights Reserved.
 * The content of this file, whole or in part, is subject to licensing terms.
 * If distributing this software, include this License Header Notice in each
 * file and provide the accompanying LICENSE file.
 */
/**
 * @author Alan Walendowski, Christopher A. Wood, Computing Science Laboratory, PARC
 * @copyright 2014-2015 Palo Alto Research Center, Inc. (PARC), A Xerox Company. All Rights Reserved.
 */

#ifndef fileio_h
#define fileio_h

#include <parc/algol/parc_Buffer.h>

/**
 * Given a fileName and chunk number, retrieve that chunk from the specified file. The
 * contents of the chunk are returned an array that must eventually be freed.
 *
 * @param [in] fileName A pointer to a string containing the name of the file to read from.
 * @param [in] chunkSize The maximum number of bytes to be returned in each chunk.
 * @param [in] chunkNumber The 0-based number of chunk to return from the file.
 *
 * @return A newly malloc'd byte array.
 */
uint8_t *fileio_GetFileChunk(const char *fileName, size_t chunkSize, uint64_t chunkNumber);

/**
 * Given a byte array, append its contents to the file specified by the given fileName.
 *
 * @param [in] fileName A pointer to a string containing the name of the file to write to.
 * @param [in] chunk A byte array pointer.
 * @param [in] length The number of bytes in the array to write
 *
 * @return The number of bytes written to the file.
 */
size_t fileio_AppendFileChunk(const char *fileName, const uint8_t *chunk, size_t length);

/**
 * Check if a file exists and is readable.
 * Return true if it does, false otherwise.
 *
 * @param [in] fileName A pointer to a string containing the name of the file to test.
 *
 * @return true If the file exists and is readable.
 * @return false If the file doesn't exist or is not readable.
 */
bool fileio_IsFileAvailable(const char *fileName);

/**
 * Return the size, in bytes, of the specified file.
 *
 * @param [in] fileName A pointer to a string containing the name of file from which to get the size.
 *
 * @return The size of the file, in bytes.
 */
size_t fileio_GetFileSize(const char *fileName);

/**
 * Delete the file specified.
 *
 * @param [in] fileName A pointer to a string containing the name of the file to delete.
 *
 * @return true If the file was successfully deleted.
 * @return false If the file was not deleted.
 */
bool fileio_DeleteFile(const char *fileName);

#endif // fileio_h
