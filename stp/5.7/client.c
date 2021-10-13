#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

void main () {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(27016);
    server.sin_addr.s_addr = INADDR_ANY;
    char sbuf[] = "HELLO FROM AUTOCLIENT\n";
    char rbuf[128];

    //int br = bind(ss, (struct sockaddr*)&server, sizeof(server));
    connect(ss, (struct sockaddr*)&server, sizeof(server));
    send(ss, &sbuf, sizeof(sbuf), 0);
    recv(ss, &rbuf, sizeof(rbuf), 0);
    close(ss);
}