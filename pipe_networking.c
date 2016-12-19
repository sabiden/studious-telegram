#include "pipe_networking.h"

int client_handshake(int* x){
  //Making the Private Pipe
  char * randStr;
  int fd = open("/dev/urandom", O_RDONLY);
  read(fd, randStr, MESSAGE_BUFFER_SIZE);
  mkfifo(randStr, 0644);
  printf("[CLIENT]: Pipe made: %s\n", randStr);

  //Opening the Well Known Pipe
  *x = open("WKP", O_WRONLY);
  write(*x, randStr, 6);
  printf("[CLIENT]: Waiting for connection...\n");
  int PP = open(randStr, O_RDONLY);
  char buffer[MESSAGE_BUFFER_SIZE];
  read(PP, buffer, MESSAGE_BUFFER_SIZE);
  printf("[CLIENT]: Received: %s\n", buffer);
  int errno = remove(randStr);
  return PP; 
}

int server_handshake(int* x){
  //Creating the Well Known Pipe
  mkfifo("WKP", 0644);

  //Waiting for input
  printf("[SERVER]: WKP made\n");
  printf("[SERVER]: Waiting for connection...\n");
  *x = open("WKP", O_RDONLY);
  char pp[MESSAGE_BUFFER_SIZE];
  read(*x, pp, MESSAGE_BUFFER_SIZE);
  int errno = remove("WKP");

  //Printing out connection
  printf("[SERVER]: Connection made with: %s\n", pp);

  //Writing to the Client
  int to_client = open(pp, O_WRONLY);
  write(to_client, "Connected", 10);
  return to_client;
}
