#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int zerocount(char zeroes[]) {
    int counter = 0;
    int zrs;
    char zc[1] = {"0"};
    long unsigned int lenarr = strlen(zeroes);

    for (counter; counter < strlen(zeroes); ++counter) {
        //printf("Index Elem %i\n", counter);
        printf("Value Elem %c\n", zeroes[counter]);
        if (zeroes[counter] == zc[0]) {
            printf("IF\n");
            ++zrs;
        }
    }
    printf("Zero at array: %d\n", zrs);
}

void main(int argc, char* argv[]) {
    printf("argc: %d\n", argc);
    printf("arg[1]: %s\n", argv[1]);
    printf("arg[1]: %s\n", argv[2]);
    if (argc < 2) {
        exit(12);
    }  
    zerocount(argv[2]);
    execve(argv[1], &argv[2], NULL);
    //sleep(10);
    fclose(stdin);
    //sleep(10);
    fclose(stdout);
    //sleep(10);
}