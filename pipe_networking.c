#include "pipe_networking.h"

int client_handshake(int* x){
  mkfifo("25645", 0644);
  printf("[CLIENT]: 25645 Pipe made\n");
  *x = open("WKP", O_WRONLY);
  write(*x,"25645", 6);
  printf("[CLIENT]: Waiting for connection...\n");
  int pp = open("25645", O_RDONLY);
  char buffer[MESSAGE_BUFFER_SIZE];
  read(pp, buffer, strlen(buffer));
  printf("[CLIENT]: Received: %s\n", buffer);
  //remove
  return pp; 
}

int server_handshake(int* x){
  mkfifo("WKP", 0644);
  printf("[SERVER]: WKP made\n");
  printf("[SERVER]: Waiting for connection...\n");
  *x = open("WKP", O_RDONLY);
  char pp[MESSAGE_BUFFER_SIZE];
  read(*x, pp, strlen(pp));
  printf("[SERVER]: Connection made with: %s\n", pp);
  int fd = open(pp, O_WRONLY);
  write(fd, "Connected", 10);
  return fd;
}
