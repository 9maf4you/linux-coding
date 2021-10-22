#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>


void main() {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char sbuf[] = "";
    char rbuf[128] = "";
    char OFF[] = "OFF\r\n";

    int br = bind(ss, (struct sockaddr*)&server, sizeof(server));
    if (br != 0) {
        puts("CAN'T BIND");
        exit(1);
    }

    int err = listen(ss, 1);
    if (err != 0) {
        puts("CAN'T listen");
        exit(1);
    }

    //idea is to reset connection right after acccepting it
    while (1) {
        int sfque = accept(ss, NULL, NULL);
        close(sfque);
    }
    
}

