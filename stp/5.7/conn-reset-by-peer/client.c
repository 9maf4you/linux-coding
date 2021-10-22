#include <sys/socket.h>
#include <errno.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void main () {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char sbuf[] = "HELLO FROM AUTOCLIENT\n";
    char rbuf[128];

    int rv = connect(ss, (struct sockaddr*)&server, sizeof(server));
    if ( errno == ECONNREFUSED ) {
        printf("errno: %d, %s\n", errno, "Connection refused");
        close(ss);
        exit(errno);
    }

    int bs = send(ss, &sbuf, sizeof(sbuf), 0);
    printf("bytes send: %d\n", bs);

    int rb = recv(ss, &rbuf, sizeof(rbuf), 0);
    printf("bytes recv: %d\n", rb);

    if ( rb == -1 ) {
        if ( errno == ECONNRESET ) {
            printf("errno: %d, %s\n", ECONNRESET, "connection reset by peer");
        }
        close(ss);
        exit(errno);
    }
    close(ss);
}
