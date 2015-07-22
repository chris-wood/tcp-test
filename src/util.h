#include <stdio.h>
#include <stdlib.h>

#ifndef UTIL_H_
#define UTIL_H_

#define RCVBUFSIZE 128

#define MAX_NUMBER_OF_TCP_CONNECTIONS 5
#define MAX_NUMBER_OF_SCTP_OSTREAMS 5
#define MAX_NUMBER_OF_SCTP_ISTREAMS 4
#define MAX_NUMBER_OF_SCTP_ATTEMPTS 4

#define DEBUG 1

void LogFatal(char *errorMessage);

#endif // UTIL_H_

