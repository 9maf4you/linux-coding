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
    printf("Zero at array: %d\n", zrs);
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
        char cbuf[] = "";
        read(STDIN_FILENO, &cbuf, 16);
        puts(cbuf);
        //sleep(300);
    } else {
        //parent
        //char pbuf[] = "STDOUT_FILENO";
        dup2(pipefd[1], STDOUT_FILENO);
        execl(argv[2], argv[2], NULL);
        //sleep(300); //write(pipefd[1], pbuf, 16);

    }
}