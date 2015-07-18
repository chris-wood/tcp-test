#include <stdio.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tcp-util.h"

#define FILE_BUFFER_LENGTH 256

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned short port;

    int directoryLength;
    char *directory;
} TCPServer;

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned int length;
} TCPClient;

void 
TCPServer_ServeClient(TCPServer *server, TCPClient *client)
{
    char nameBuffer[RCVBUFSIZE];
    int recvMsgSize;

    if ((recvMsgSize = recv(client->socket, nameBuffer, RCVBUFSIZE, 0)) < 0) {
        LogFatal("recv() failed");
    }

    // while (recvMsgSize > 0) {
    //     // Send message back to the client...
    //     if (send(client->socket, nameBuffer, recvMsgSize, 0) != recvMsgSize) {
    //         LogFatal("send() failed");
    //     }

    //     // get some data...
    //     if ((recvMsgSize = recv(client->socket, nameBuffer, RCVBUFSIZE, 0)) < 0) {
    //         LogFatal("recv() failed");
    //     }
    // }

    fprintf(stderr, "Reading %s\n", nameBuffer);

    FILE *fp = fopen(nameBuffer, "r");
    if (fp != NULL) {
        char *message = "File does not exist";
        int length = strlen(message);
        if (send(client->socket, message, length, 0) != length) {
            LogFatal("send() failed");
        }
    }

    char fileBuffer[FILE_BUFFER_LENGTH];
    size_t numBytesRead = 0;
    while (!feof(fp)) {
        numBytesRead = fread(fileBuffer, 1, FILE_BUFFER_LENGTH, fp);
        if (numBytesRead != FILE_BUFFER_LENGTH && !feof(fp)) {
            LogFatal("fread() failed");
        }
        send(client->socket, fileBuffer, numBytesRead, 0);
    }

    close(client->socket);
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
    server.directoryLength = strlen(argv[2]);
    server.directory = (char *) malloc(server.directoryLength * sizeof(char));
    strncpy(server.directory, argv[2], server.directoryLength);

    if ((server.socket = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
        LogFatal("socket() failed");
    }
      
    memset(&(server.address), 0, sizeof(server.address));
    server.address.sin_family = AF_INET;
    server.address.sin_addr.s_addr = htonl(INADDR_ANY);
    server.address.sin_port = htons(server.port);

    if (bind(server.socket, (struct sockaddr *) &(server.address), sizeof(server.address)) < 0) {
        LogFatal("bind() failed");
    }
        
    if (listen(server.socket, MAX_NUMBER_OF_CONNECTIONS) < 0) {
        LogFatal("listen() failed");
    }

    for (;;) {
        TCPClient client;
        client.length = sizeof(client.address);

        if ((client.socket = accept(server.socket, (struct sockaddr *) &(client.address), &client.length)) < 0) {
            LogFatal("accept() failed");
        }   

#if DEBUG
        fprintf(stderr, "Handling client %s\n", inet_ntoa(client.address.sin_addr));
#endif

        TCPServer_ServeClient(&server, &client);
    }

    free(server.directory);
    
    return 0;
}
