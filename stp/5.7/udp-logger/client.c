#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <errno.h>

void main () {
    int ss = socket(AF_INET, SOCK_DGRAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char sbuf[] = "HELLO FROM UDP-AUTOCLIENT\n";
    char rbuf[128];

    int rv = connect(ss, (struct sockaddr*)&server, sizeof(server));
    if ( rv != 0 ) {
        puts("cannot connect");
        exit(1);
    }
    int sb = send(ss, &sbuf, sizeof(sbuf), 0);
    if ( sb == -1 ) {
        puts("SEND ERROR");
        printf("ERRNO: %d\n", errno);
    }
    // recv(ss, &rbuf, sizeof(rbuf), 0); if we need to recvive something
    close(ss);
}
