#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main ()
{
    pid_t child_pid;
    for ( int i = 0; i < 50; i++ ) {
        sleep(1);
        //puts("go");
        child_pid = fork ();
        if (child_pid == 0) {
            sleep(i);
            exit(2);
            }
    }
    sleep(1000);
}