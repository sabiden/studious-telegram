#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

#define MESSAGE_BUFFER_SIZE 100
int client_handshake(int* x);
int server_handshake(int* x);
