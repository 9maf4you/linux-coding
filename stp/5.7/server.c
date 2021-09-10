#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>



void main() {
    int ss = socket(AF_INET, SOCK_NONBLOCK, SOCK_STREAM);
    struct sockaddr_in server;
    server.sin_addr.s_addr=INADDR_LOOPBACK;
    server.sin_family = AF_INET;
    server.sin_port = 27015;
    bind(ss, (struct sockaddr *) &server, sizeof(&server));
}