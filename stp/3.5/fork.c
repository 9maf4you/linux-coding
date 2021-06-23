#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>


int forked() {
    sleep(7);
}


int main() {
    pid_t childpid;
    childpid = fork();
    if (childpid != -1) {
        printf("PID is %d \n", childpid);
        fclose(stdout);
        forked();
    }
}
