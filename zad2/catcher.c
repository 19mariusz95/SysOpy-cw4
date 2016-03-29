#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <zconf.h>
#include "ksiadz.h"

int ala2 = 0;
union sigval s;

void alamakota(int singal) {
    switch (singal) {
        case SIGUSR1: {
            ala2++;
            break;
        }
        case SIGUSR2: {
            printf("podaj pid\n");
            int pid;
            scanf("%d", &pid);
            for (int i = 0; i < ala2; i++) {
                send_signal(pid, SIGUSR1, s);
            }
            send_signal(pid, SIGUSR2, s);
            exit(0);
        }
        default: {
            printf("Odebrano sygnal\n");
        }
    }
}

int main(int argc, char *argv[]) {

    printf("%d\n", getpid());
    fflush(stdout);

    receive_signal(alamakota);
    while (1)
        pause();
}

