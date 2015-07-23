#include <sys/socket.h>
#include <netinet/in.h>
#include <stdio.h>

#include "../util.h"

int 
main(int argc, char** argv)
{
   int socket;
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

   socket = socket(AF_INET, SOCK_DGRAM, 0);

   bzero(&servaddr, sizeof(servaddr));
   servaddr.sin_family = AF_INET;
   servaddr.sin_addr.s_addr = inet_addr(serverIPAddress);
   servaddr.sin_port = htons(serverPort);

   int fileNameLength = strlen(fileName)
   if (send(socket, fileName, fileNameLength, 0) != fileNameLength) {
      LogFatal("send() failed");
   }

#if DEBUG
   fprintf(stderr, "Received: \n"); 
#endif

   for (;;) {
      bytesReceived = recv(socket, serverResponseBuffer, RCVBUFSIZE, 0);
      totalBytesRcvd += bytesReceived;

      printf("%.*s", bytesReceived, serverResponseBuffer);

      if (bytesReceived < RCVBUFSIZE) {
         break;
      }
   }

   close(socket);

#if DEBUG
    fprintf(stderr, "\n");
#endif

    return 0;
}