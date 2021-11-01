#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>



void main () {
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    
    int ss = socket(AF_INET, SOCK_DGRAM, 0);
    if ( ss == -1 ) {
        puts("cant create socket");
        exit(1);
    }
    int br = bind(ss, (struct sockaddr*)&server, sizeof(server));
        if (br == -1) {
            puts("CAN'T BIND");
            exit(1);
    }
    
    char buf[5*1024];

    while (1) {
        if ( recv(ss, buf, sizeof(buf), 0) > 0) {
            puts(buf);
        }
        
    }
}