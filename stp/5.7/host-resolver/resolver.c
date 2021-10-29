#include <netdb.h>
#include <stdio.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

struct in_addr **addr_list;

int main (int c, char **hostname) {
    //struct hostent *h;
    if (c < 2) {
        puts("too small count of args\n");
        return 1;
    }
    struct hostent *h = gethostbyname(hostname[1]);
    if (h == NULL) {
        puts("An error occured\n");
        return 1;
    }
    addr_list = (struct in_addr **)h->h_addr_list;
    for (int i = 0; addr_list[i] != NULL; i++) {
        printf("has address: %s \n", inet_ntoa(*addr_list[i]));
    }
    return 0;
}