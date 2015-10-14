#include <stdio.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../util/util.h"

int
main(int argc, char *argv[])
{
    int sock;
    struct sockaddr_in serverAddress;
    unsigned short serverPort;
    char *serverIPAddress;
    char *fileName;
    char serverResponseBuffer[RCVBUFSIZE];
    unsigned int fileNameLen;
    int bytesReceived, totalBytesRcvd;

    if (argc != 4) {
       fprintf(stderr, "usage: %s <Server IP Address> <File Name> <Port>\n", argv[0]);
       exit(1);
    }

    serverIPAddress = argv[1];
    fileName = argv[2];
    serverPort = atoi(argv[3]);

    TimeBlock(stdout, {
        if ((sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
            LogFatal("socket() failed");
        }

        memset(&serverAddress, 0, sizeof(serverAddress));
        serverAddress.sin_family = AF_INET;
        serverAddress.sin_addr.s_addr = inet_addr(serverIPAddress);
        serverAddress.sin_port = htons(serverPort);

        if (connect(sock, (struct sockaddr *) &serverAddress, sizeof(serverAddress)) < 0) {
            LogFatal("connect() failed");
        }

        fileNameLen = strlen(fileName);

        if (send(sock, fileName, fileNameLen, 0) != fileNameLen) {
            LogFatal("send() sent a different number of bytes than expected");
        }

        totalBytesRcvd = 0;
#if DEBUG
        fprintf(stderr, "Received: \n");
#endif
        for (;;) {

            bytesReceived = recv(sock, serverResponseBuffer, RCVBUFSIZE, 0);
            totalBytesRcvd += bytesReceived;

            printf("%.*s", bytesReceived, serverResponseBuffer);

            if (bytesReceived < RCVBUFSIZE) {
                break;
            }
        }

#if DEBUG
        fprintf(stderr, "\n");
#endif

        close(sock);
    });

    return 0;
}
