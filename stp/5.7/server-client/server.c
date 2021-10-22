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
    int backlogsize = 1;

        int foo = 0;
        printf("%d\n",foo);
        foo = ++foo;
        printf("%d\n",foo);
        foo = 0;
    
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
        int childs = 0;
        int fdc = accept(ss, NULL, NULL);
        printf("new connection fd: %d\n", fdc);
        if ( fdc != -1 ) {
            if ( backlogsize == childs ){
                puts("too much connection");
                close(fdc);
            } else {
                puts("increase client count");
                childs = ++childs; 
                printf("client count: %d\n", childs);
            }

            pid_t pid = fork();
            if ( pid != 0 ) {
                //puts("New child has been born\n");
                talker(fdc);
                childs = --childs; 
                printf("decriment client count: %d\n", childs);
            }
        };
    }
}

