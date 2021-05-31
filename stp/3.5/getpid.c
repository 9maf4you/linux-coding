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
    //strset for formatinf strings

    puts(buf);
}