#include <stdio.h> 
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "tcp-util.h"

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned short port;
} TCPServer;

typedef struct {
    int socket;
    struct sockaddr_in address;
    unsigned int length;
} TCPClient;

void 
TCPServer_ServeClient(TCPServer *server, TCPClient *client)
{
    char echoBuffer[RCVBUFSIZE];
    int recvMsgSize;

    // get some data...
    if ((recvMsgSize = recv(client->socket, echoBuffer, RCVBUFSIZE, 0)) < 0) {
        LogFatal("recv() failed");
    }

    while (recvMsgSize > 0) {
        // Send message back to the client...
        if (send(client->socket, echoBuffer, recvMsgSize, 0) != recvMsgSize) {
            LogFatal("send() failed");
        }

        // get some data...
        if ((recvMsgSize = recv(client->socket, echoBuffer, RCVBUFSIZE, 0)) < 0) {
            LogFatal("recv() failed");
        }
    }

    close(client->socket);
}

int 
main(int argc, char *argv[])
{
    TCPServer server;

    if (argc != 2) {
        fprintf(stderr, "Usage:  %s <Server Port>\n", argv[0]);
        exit(1);
    }

    server.port = atoi(argv[1]);  /* First arg:  local port */

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

    for (;;)
    {
        TCPClient client;
        client.length = sizeof(client.address);

        /* Wait for a client to connect */
        if ((client.socket = accept(server.socket, (struct sockaddr *) &(client.address), 
                               &client.length)) < 0) {
            LogFatal("accept() failed");
        }   

        printf("Handling client %s\n", inet_ntoa(client.address.sin_addr));

        TCPServer_ServeClient(&server, &client);
    }
    
    return 0;
}
