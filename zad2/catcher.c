#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <zconf.h>

void receive_signal();

void alamakota(int singal) {
    switch (singal) {
        case SIGUSR1: {

            break;
        }
        case SIGUSR2: {
            break;
        }
        default: {
            printf("Odebrano sygnal\n");
        }
    }
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

