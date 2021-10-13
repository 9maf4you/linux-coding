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

    listen(ss, 1);
    int sr = accept(ss, NULL, NULL);

    uint8_t spos = 0;
    uint8_t endpos = 0;
    while (1) {
        if ( recv(sr, &rbuf, sizeof(rbuf), 0) == 0 ){
            sleep(0.5);
        };
        if (strncmp("OFF", rbuf, 3) == 0) {
            puts("OFF FOUND");
            close(sr);
            exit(0);
        } else {
            printf("SEND IT BACK: %s", rbuf);
            send(sr, &rbuf, sizeof(rbuf), MSG_NOSIGNAL);
        }
    };
}