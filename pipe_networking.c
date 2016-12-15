#include "pipe_networking.h"

int client_handshake(int* x){
  mkfifo("25645", 0644);
  printf("[CLIENT]: PP made\n");
  int fd = open("server", O_WRONLY);
  write(fd,"25645", 6);
  printf("[CLIENT]: Waiting for connection...\n");
  fd = open("25645", O_RDONLY);
  char buffer[MESSAGE_BUFFER_SIZE];
  read(fd, buffer, strlen(buffer));
  printf("[CLIENT]: %s...\n", buffer);
  close(fd);
  
}
int server_handshake(int* x){
  mkfifo("server", 0644);
  printf("[SERVER]: WKP made\n");
  printf("[SERVER]: Waiting for connection...\n");
  int fd = open("server", O_RDONLY);
  char buffer[MESSAGE_BUFFER_SIZE];
  read(fd, buffer, strlen(buffer));
  printf("[SERVER]: Connection made with: %s", buffer);
  close(fd);
  fd = open(buffer, O_WRONLY);
  char mssg[] = 'connected';
  write(fd, mssg, strlen(mssg));
}
