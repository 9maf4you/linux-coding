#include <sys/socket.h>
#include <netinet/in.h>

void main () {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    char buf[] = "HELLO FROM AUTOCLIENT";

    int br = bind(ss, (struct sockaddr*)&server, sizeof(server));
    connect(br, (struct sockaddr*)&server, sizeof(server));
    //send();
}