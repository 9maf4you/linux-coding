#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void main() {
    key_t key = 42;
    int id = shmget(key, 0, 0);
    int *add = shmat(id, NULL, SHM_RDONLY);
    printf("DATA IS: %d\n", *add);
}