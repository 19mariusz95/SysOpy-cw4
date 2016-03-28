#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <zconf.h>
#include "ksiadz.h"

int ala2 = 0;
union sigval s;
int pid;

void alamakota(int singal) {
    switch (singal) {
        case SIGUSR1: {
            ala2++;
            printf("%d odebrano sigusr1\n", ala2);
            fflush(stdout);
            send_signal(pid, SIGUSR1, s);
            break;
        }
        case SIGUSR2: {
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

    printf("podaj pid\n");
    pid;
    scanf("%d", &pid);

    while (1)
        receive_signal(alamakota);
}