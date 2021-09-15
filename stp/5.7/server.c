#include <sys/socket.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <unistd.h>



void main() {
    int ss = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = 27015;
    server.sin_addr.s_addr=INADDR_ANY;
    
    
    bind(ss, (struct sockaddr *) &server, sizeof(&server));
    sleep(300);
}