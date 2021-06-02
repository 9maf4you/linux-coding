#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>


int main(){
    int pid;
    int fd;
    char buf[1024];
    char d;
    fd = open("/proc/self/stat", 0);
    read(fd, &buf, 1024);
    
    char *istr;
    char sep[10] = " ";
    istr = strtok(buf, sep);

    int c = 1;
    while (istr != NULL) {
        if ( c == 4 ) {
            printf("the parent pid is: %s\n", istr);
            break;
        }
        istr = strtok(NULL, sep);
        c++;
    }
    
}