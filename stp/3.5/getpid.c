#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>


int main(){
    int pid;
    int fd;
    char buf;
    char d;
    char str[60];
    
    pid = getpid();
    sprintf(&str, "/proc/%u/stat", pid);
    fd = open(str, 0);
    d = read(fd, &buf, 1024);
}