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
    unsigned int backlogsize = 1;
    unsigned int childs = 0;
    

    int br = bind(ss, (struct sockaddr*)&server, sizeof(server));
    if (br != 0) {
        puts("CAN'T BIND");
        exit(1);
    }

    int err = listen(ss, backlogsize);
    if (err != 0) {
        puts("CAN'T listen");
        exit(1);
    }

    int talker(int fd) {
        char childbuf[128];
        printf("reading from a client\n");
        while ( recv(fd, &childbuf, sizeof(childbuf), 0) != 0 ) {
            printf("msg: %s\n", childbuf);
        }
        close(fd);
        printf("file descriptor %d closed\n", fd);
        return 0;
    };




    while (1) {
        unsigned int fdc = accept(ss, NULL, NULL);
        printf("new connection fd: %d\n", fdc);
        printf("backlog: %d, childs: %d\n", backlogsize, childs);
        if ( fdc != -1 ) {
            if ( backlogsize <= childs ){
                puts("too much connection\n\n\n");
                setsockopt(fdc, 1, 0, 0, 0);
                close(fdc);
            } else {
                puts("increase client count");
                childs++; 
                printf("client count: %d\n", childs);

                pid_t pid = fork();
                if ( pid != 0 ) {
                    talker(fdc);
                    childs--; 
                    printf("decriment client count: %d\n", childs);
                }
            }
        };
    }
}

