#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include "../util/util.h"

int
main(int argc, char** argv)
{
    int socketfd;
    struct sockaddr_in servaddr,cliaddr;
    char serverResponseBuffer[RCVBUFSIZE];
    int bytesReceived;
    int totalBytesRcvd;

    if (argc != 4) {
        fprintf(stderr, "usage: %s <Server IP Address> <File Name> <Port>\n", argv[0]);
        exit(1);
    }

    char *serverIPAddress = argv[1];
    char *fileName = argv[2];
    int serverPort = atoi(argv[3]);

    TimeBlock(stdout, {
        socketfd = socket(AF_INET, SOCK_DGRAM, 0);

        bzero(&servaddr, sizeof(servaddr));
        servaddr.sin_family = AF_INET;
        servaddr.sin_addr.s_addr = inet_addr(serverIPAddress);
        servaddr.sin_port = htons(serverPort);

        int fileNameLength = strlen(fileName);
        if (send(socketfd, fileName, fileNameLength, 0) != fileNameLength) {
            LogFatal("send() failed");
        }

#if DEBUG
        fprintf(stderr, "Received: \n");
#endif

        for (;;) {
            bytesReceived = recv(socketfd, serverResponseBuffer, RCVBUFSIZE, 0);
            totalBytesRcvd += bytesReceived;

            printf("%.*s", bytesReceived, serverResponseBuffer);

            if (bytesReceived < RCVBUFSIZE) {
                break;
            }
        }

#if DEBUG
        fprintf(stderr, "\n");
#endif

        close(socketfd);
    });

    return 0;
}
