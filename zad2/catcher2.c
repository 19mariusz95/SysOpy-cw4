#include <stdlib.h>
#include <stdio.h>
#include "ksiadz.h"
#include "ksiadz3.h"

int ala2 = 0;
union sigval s;
int wait = 1;
int flaga = 1;
siginfo_t inf;

void alamakota(int singal, siginfo_t *info, void *cont) {
    inf = *info;
    switch (singal) {
        case SIGUSR1: {
            if (flaga) {
                ala2++;
                send_signal(info->si_pid, SIGUSR1, s);
            } else {
                wait = 0;
            }
            break;
        }
        case SIGUSR2: {
            flaga = 0;
        }
        default: {
        }
    }
}

int main(int argc, char *argv[]) {

    receive_signal(alamakota);
    while (flaga);

    printf("Odebrano %d sygnalow SIGUSR1. Wysylanie do sendera\n", ala2);
    for (int i = 0; i < ala2; i++) {
        send_signal(inf.si_pid, SIGUSR1, s);
        while (wait);
        wait = 1;
    }
    send_signal(inf.si_pid, SIGUSR2, s);
    exit(0);
}