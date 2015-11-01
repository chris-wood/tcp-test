#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#include "../util/util.h"

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned short port;

    int fileLength;
    char *file;
} TCPServer;

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned int length;
} TCPClient;

void
TCPServer_ServeClient(TCPServer *server, TCPClient *client)
{
    char *nameBuffer = (char *) malloc(RCVBUFSIZE * sizeof(char));
    int recvMsgSize;

    if ((recvMsgSize = recv(client->socket, nameBuffer, RCVBUFSIZE, 0)) < 0) {
        LogFatal("recv() failed");
    }

    if (recvMsgSize < RCVBUFSIZE) {
        nameBuffer[recvMsgSize] = 0; // null terminator
    } else {
        // read more and expand the buffer
    }

    FILE *fp = fopen(nameBuffer, "r");
    if (fp == NULL) {

#if DEBUG
        fprintf(stderr, "File %s does not exist", nameBuffer);
#endif

        char *message;
        asprintf(&message, "File %s does not exist", nameBuffer);

        int length = strlen(message);
        if (send(client->socket, message, length, 0) != length) {
            LogFatal("send() failed");
        }
    } else {

#if DEBUG
        fprintf(stderr, "Reading file: %s", nameBuffer);
#endif

        char fileBuffer[FILE_BUFFER_LENGTH];
        size_t numBytesRead = 0;
        for (;;) {
            numBytesRead = fread(fileBuffer, 1, FILE_BUFFER_LENGTH, fp);
            if (send(client->socket, fileBuffer, numBytesRead, 0) != numBytesRead) {
                LogFatal("Error sending data to the client\n");
            }

            if (numBytesRead != FILE_BUFFER_LENGTH) {
                break;
            }
        }

        close(client->socket);
    }

#if DEBUG
    fprintf(stderr, "Done serving the client...\n");
#endif
    free(nameBuffer);
}

int
main(int argc, char *argv[])
{
    TCPServer server;

    if (argc != 3) {
        fprintf(stderr, "Usage: %s <Server Port> <Directory>\n", argv[0]);
        exit(1);
    }

    server.port = atoi(argv[1]);
    server.fileLength = strlen(argv[2]);
    server.file = (char *) malloc(server.fileLength * sizeof(char));
    strncpy(server.file, argv[2], server.fileLength);

    if ((server.socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        LogFatal("socket() failed");
    }

    memset(&(server.address), 0, sizeof(server.address));
    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = htonl(INADDR_ANY);
    server.address.sin_port = htons(server.port);

    int on = 1;
    if (setsockopt(server.socket, SOL_SOCKET, SO_REUSEADDR, (const char *) &on, sizeof(on)) < 0) {
        LogFatal("setsockopt() failed");
    }

    if (bind(server.socket, (struct sockaddr *) &(server.address), sizeof(server.address)) < 0) {
        LogFatal("bind() failed");
    }

    // set address reuse
    int optval = 1;
    setsockopt(server.socket, SOL_SOCKET, SO_REUSEADDR, (const void *) &optval , sizeof(int));

    if (listen(server.socket, MAX_NUMBER_OF_TCP_CONNECTIONS) < 0) {
        LogFatal("listen() failed");
    }

    TCPClient client;
    client.length = sizeof(client.address);

    if ((client.socket = accept(server.socket, (struct sockaddr *) &(client.address), &client.length)) < 0) {
        LogFatal("accept() failed");
    }

#if DEBUG
    fprintf(stderr, "Handling client %s\n", inet_ntoa(client.address.sin_addr));
#endif

    TCPServer_ServeClient(&server, &client);

#if DEBUG
    fprintf(stderr, "Done with client %s\n", inet_ntoa(client.address.sin_addr));
#endif

    free(server.file);
    close(server.socket);

    return 0;
}
