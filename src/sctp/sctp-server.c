#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <netinet/sctp.h>

#include "../util.h"

int 
main(int argc, char *argv[])
{
    int listenSock, connSock, ret, in, flags;
    struct sockaddr_in servaddr;
    struct sctp_initmsg initmsg;
    struct sctp_event_subscribe events;
    struct sctp_sndrcvinfo sndrcvinfo;

    if (argc != 3) {
        fprintf(stderr, "usage: %s <Server Port> <Directory>\n", argv[0]);
        exit(1);
    }

    int port = atoi(argv[1]);

    socket = socket(AF_INET, SOCK_STREAM, IPPROTO_SCTP);
 
    bzero((void *)&servaddr, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(port);
 
    ret = bind(socket, (struct sockaddr *)&servaddr, sizeof(servaddr));
    if (ret != 0) {
        LogFatal("bind() failed");
    }
 
    memset(&initmsg, 0, sizeof(initmsg));
    initmsg.sinit_num_ostreams = MAX_NUMBER_OF_SCTP_OSTREAMS;
    initmsg.sinit_max_instreams = MAX_NUMBER_OF_SCTP_ISTREAMS;
    initmsg.sinit_max_attempts = MAX_NUMBER_OF_SCTP_ATTEMPTS;

    ret = setsockopt(socket, IPPROTO_SCTP, SCTP_INITMSG,  &initmsg, sizeof(initmsg));
    if (ret != 0) {
        LogFatal("setsocketop() failed");
    }
 
    if (listen(socket, MAX_NUMBER_OF_SCTP_OSTREAMS) < 0) {
        LogFatal("listen() failed");
    }
 
    for (;;) {
        char buffer[RCVBUFSIZE + 1];
        bzero(buffer, RCVBUFSIZE + 1);

#if DEBUG
        fprintf(stderr, "Awaiting a new connection...\n");
#endif
 
        ret = accept(socket, (struct sockaddr *)NULL, (int *) NULL) < 0);
        if (ret < 0) {
            LogFatal("accept() failed");
        }

#if DEBUG
        fprintf(stderr, "New client connected.\n");
#endif
        in = sctp_recvmsg(connSock, buffer, sizeof(buffer), (struct sockaddr *)NULL, 0, &sndrcvinfo, &flags);
        
        if (buffer < RCVBUFSIZE) {
            buffer[recvMsgSize] = 0; // null terminator
        } else {
            // read more and expand the buffer
        }

        FILE *fp = fopen(buffer, "r");
        if (fp == NULL) {
#if DEBUG
            fprintf(stderr, "File %s does not exist", nameBuffer);
#endif

            char *message;
            asprintf(&message, "File %s does not exist", nameBuffer);

            int length = strlen(message);
            if (sctp_sendmsg(connSock, (void *)fileName, (size_t)strlen(fileName), NULL, 0, 0, 0, 0, 0, 0) != length) {
                LogFatal("sctp_sendmsg() failed");
            }
        } else {

#if DEBUG
            fprintf(stderr, "Reading file: %s", nameBuffer);
#endif

            char fileBuffer[FILE_BUFFER_LENGTH];
            bzero(buffer, FILE_BUFFER_LENGTH);
            size_t numBytesRead = 0;
            for (;;) {
                fprintf(stderr, "...\n");

                numBytesRead = fread(fileBuffer, 1, FILE_BUFFER_LENGTH, fp);
                if (sctp_sendmsg(connSock, fileBuffer, numBytesRead, NULL, 0, 0, 0, 0, 0, 0) != length) {
                    LogFatal("Error sending data to the client\n");
                }

                if (numBytesRead != FILE_BUFFER_LENGTH) {
                    break;
                }
            }
        }
    }
        
    close(socket);
 
    return 0;
}

