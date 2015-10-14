#include <stdio.h>
#include <stdlib.h>

#ifndef UTIL_H_
#define UTIL_H_

#include <time.h>

#define RCVBUFSIZE 128

#define FILE_BUFFER_LENGTH 256

#define MAX_NUMBER_OF_TCP_CONNECTIONS 5
#define MAX_NUMBER_OF_SCTP_OSTREAMS 5
#define MAX_NUMBER_OF_SCTP_ISTREAMS 4
#define MAX_NUMBER_OF_SCTP_ATTEMPTS 4

#define DEBUG 1

typedef struct timeval TimeValue;

void LogFatal(char *errorMessage);

#define TimeBlock(_out, _block) \
    struct timeval start; \
    struct timeval end; \
    struct timeval delta; \
    gettimeofday(&start, NULL); \
    _block \
    gettimeofday(&end, NUL); \
    timeval_subtract(&diff, &start, &end); \
    fprintf(_out, (diff.tv_sec * 1000000L) + diff.tv_usec);

#endif // UTIL_H_
