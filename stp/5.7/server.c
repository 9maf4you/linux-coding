#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>


void main() {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char buf[24];
    char OFF[] = "OFF\r\n";

    bind(ss, (struct sockaddr*)&server, sizeof(server));
    listen(ss, 1);
    int sr = accept(ss, NULL, NULL);
    while ( strcmp(buf, OFF) ) {
        recv(sr, &buf, 24, 0);
        puts(buf);
    };
    close(ss);
}