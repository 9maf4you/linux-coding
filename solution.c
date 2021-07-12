#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int forked(){
    pid_t pid;
    pid = getpid();
    printf("%d\n", pid);
    fclose(stdout);
    sleep(10);
}


int main(){
    pid_t childpid;
    childpid = fork();
    setsid();
    if (childpid == 0) { 
        forked();
    } else {
        sleep(1);
    }
}
