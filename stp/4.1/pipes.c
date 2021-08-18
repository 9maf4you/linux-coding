#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/wait.h>

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
    printf("Zero at array: %d\n", zrs);
    return zrs;
}

void main(int argc, char* argv[]) {
    if (argc < 2) {
        exit(12);
    }  
    
    int pipefd[2];
    pipe(pipefd);

    if ( fork() == 0 ) {
        //child
        char buf;
        close(pipefd[1]);
        dup2(pipefd[0], STDIN_FILENO);

        int zc = 0;
        while ( read(STDIN_FILENO, &buf, 8) > 0)
            zc += zerocount(&buf);
        
        printf("%i",zc);
        close(pipefd[0]);
        close(STDIN_FILENO);
    } else {
        //parent
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        //The command "./pipes.bin sleep 10"
        //shows up: execve("/usr/bin/sleep", ["sleep", "10"], 0x7ffff53580c8 /* 18 vars */) =  0
        //....wierd
        execlp(argv[1], argv[1], argv[2], NULL);
        close(pipefd[1]);
        close(STDOUT_FILENO);
        wait(NULL);
        exit(EXIT_SUCCESS);
    }
}