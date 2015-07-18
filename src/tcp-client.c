#include <stdio.h>      
#include <sys/socket.h> 
#include <arpa/inet.h>  
#include <stdlib.h>     
#include <string.h>     
#include <unistd.h>  

#include "tcp-util.h"

int 
main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in echoServAddr;
    unsigned short echoServPort;
    char *servIP;
    char *echoString;
    char echoBuffer[RCVBUFSIZE];
    unsigned int echoStringLen;
    int bytesRcvd, totalBytesRcvd;

    if ((argc < 3) || (argc > 4)) {
       fprintf(stderr, "Usage: %s <Server IP> <Echo Word> [<Echo Port>]\n", argv[0]);
       exit(1);
    }

    servIP = argv[1];
    echoString = argv[2];

    if (argc == 4) {
        echoServPort = atoi(argv[3]); /* Use given port, if any */
    } else {
        echoServPort = 7;  /* 7 is the well-known port for the echo service */
    }

    if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        LogFatal("socket() failed");
    }

    memset(&echoServAddr, 0, sizeof(echoServAddr)); 
    echoServAddr.sin_family = AF_INET;
    echoServAddr.sin_addr.s_addr = inet_addr(servIP);
    echoServAddr.sin_port = htons(echoServPort);

    if (connect(sock, (struct sockaddr *) &echoServAddr, sizeof(echoServAddr)) < 0) {
        LogFatal("connect() failed");
    }

    echoStringLen = strlen(echoString);

    if (send(sock, echoString, echoStringLen, 0) != echoStringLen) {
        LogFatal("send() sent a different number of bytes than expected");
    }

    totalBytesRcvd = 0;
#if DEBUG
    fprintf(stderr, "Received: "); 
#endif
    while (totalBytesRcvd < echoStringLen) {
        /* Receive up to the buffer size (minus 1 to leave space for
           a null terminator) bytes from the sender */
        if ((bytesRcvd = recv(sock, echoBuffer, RCVBUFSIZE - 1, 0)) <= 0) {
            LogFatal("recv() failed or connection closed prematurely");
        }
        totalBytesRcvd += bytesRcvd;
        echoBuffer[bytesRcvd] = '\0';
#if DEBUG
        fprintf("%s", echoBuffer);
#endif
    }

#if DEBUG
    fprintf("\n");
#endif

    close(sock);

    return 0;
}

