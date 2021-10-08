#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>


void main() {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char buf[24];
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
        recv(sr, &buf, 24, 0);
        if (strncmp("OFF", buf, 3) == 0) {
            puts("OFF FOUND");
            exit(0);
        } else {
            printf("SEND IT BACK: %s", buf);
            send(sr, &buf, sizeof(&buf), 0);
        }
        sleep(1);
    };
}