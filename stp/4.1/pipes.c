#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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
}

void main(int argc, char* argv[]) {
    printf("argc: %d\n", argc);
    printf("arg[1]: %s\n", argv[1]);
    printf("arg[2]: %s\n", argv[2]);
    if (argc < 2) {
        exit(12);
    }  
    
    execve(argv[2], &argv[3], NULL);
    zerocount(argv[2]);
    
}