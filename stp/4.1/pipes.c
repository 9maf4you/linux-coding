#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

int zerocount(char zeroes[]) {
    int counter = 0;
    int zrs = 0;
    char zc[1] = {"0"};
    long unsigned int lenarr = strlen(zeroes);

    for (counter; counter < strlen(zeroes); ++counter) {
        //printf("Value Elem %c\n", zeroes[counter]);
        if (zeroes[counter] == zc[0]) {
            ++zrs;
        }
    }
    //printf("Zero at array: %d\n", zrs);
    return zrs;
}

void main(int argc, char* argv[]) {
    if (argc < 2) {
        exit(12);
    }  
    
    int pipefd[2];    
    int iofd = pipe(pipefd);

    if ( fork() == 0 ) {
        //child
        dup2(pipefd[0], STDIN_FILENO);
        close(4);
        close(3);
        char cbuf[] = "";
        read(STDIN_FILENO, &cbuf, 16);
        puts("CHILD START");
        int zc;
        zc = zerocount(cbuf);
        printf("CHILD COUNTED: %d\n", zc);
        puts("CHILD END");
        sleep(300);
    } else {
        //parent
        char pbuf[] = "STDOUT_FILENO";
        dup2(pipefd[1], STDOUT_FILENO);
        close(4);
        close(3);
        //The command "./pipes.bin sleep 10"
        //shows up: execve("/usr/bin/sleep", ["sleep", "10"], 0x7ffff53580c8 /* 18 vars */) =  0
        //....wierd
        execlp(argv[1], argv[1], argv[2], NULL);
        write(pipefd[1], pbuf, 16);
    }
}