#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h> // will not compile on OSX -- not present
#include <arpa/inet.h>

#include "../util.h"

#define MAX_BUFFER 1024
 
int 
main(int argc, char *argv[])
{
    int connSock, in, ret, flags, bytesReceived, totalBytesRcvd;
    struct sctp_sndrcvinfo sndrcvinfo;
    struct sockaddr_in servaddr;
    struct sctp_status status;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <Server IP Address> <File Name> <Port>\n", argv[0]);
        exit(1);
    }
 
    char *serverIPAddress = argv[1];
    char *fileName = argv[2];
    int serverPort = atoi(argv[3]); 
 
    connSock = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
 
    if (connSock == -1) {
        LogFatal("socket() failed");
    }
 
    bzero((void *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(serverPort);
    servaddr.sin_addr.s_addr = inet_addr(serverIPAddress);
 
    ret = connect(connSock, (struct sockaddr *) &servaddr, sizeof(servaddr));
    if (ret < 0) {
        LogFatal("connect() failed");
    }
    
    ret = sctp_sendmsg(connSock, (void *)fileName, (size_t)strlen(fileName), NULL, 0, 0, 0, 0, 0, 0);
    if (ret < 0) {
        LogFatal("sctp_sendmsg() failed");
    }

    char serverRepsonseBuffer[RCVBUFSIZE];
    for (;;) {
        bytesReceived = sctp_recvmsg(connSock, serverRepsonseBuffer, RCVBUFSIZE, 
          (struct sockaddr *) NULL, 0, &sndrcvinfo, &flags);
        totalBytesRcvd += bytesReceived;

        printf("%.*s", bytesReceived, serverRepsonseBuffer);

        if (bytesReceived < RCVBUFSIZE) {
            break;
        }
    }

    close(connSock);
 
    return 0;
}
