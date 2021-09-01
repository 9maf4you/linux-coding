#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


void main() {
    key_t key = 42;
    int id = shmget(key, sizeof(int), 0777|IPC_CREAT);
    int *add = (int *)shmat(id, NULL, SHM_EXEC);

    *add = 1987;
    printf("DATA IS: %d\n", *add);
    sleep(300);
    // Нужно ловить сигнал ctrl+c чтобы не делать детац.
    // тогад клиент не свалится в кордамп
    shmdt(add);
}