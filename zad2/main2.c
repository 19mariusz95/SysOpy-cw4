#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <zconf.h>

void receive_signal();

void alamakota(int singal) {

    printf("Otrzymano sygnal\n");
    fflush(stdout);
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("troloolo");
        exit(1);
    }

    int ala = atoi(argv[1]);

    if (ala == 0) {
        printf("trolololo");
        exit(1);
    }

    printf("%d\n", getpid());
    fflush(stdout);

    for (int i = 0; i < ala; i++) {
        receive_signal();
    }

    return 0;
}

void receive_signal() {
    signal(SIGUSR1, alamakota);
    pause();
}

