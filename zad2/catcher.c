#include <stdlib.h>
#include <stdio.h>
#include "ksiadz.h"
#include "ksiadz3.h"

int ala2 = 0;
union sigval s;

void alamakota(int singal, siginfo_t *info, void *cont) {
    switch (singal) {
        case SIGUSR1: {
            ala2++;
            break;
        }
        case SIGUSR2: {
            for (int i = 0; i < ala2; i++) {
                send_signal(info->si_pid, SIGUSR1, s);
            }
            send_signal(info->si_pid, SIGUSR2, s);
            exit(0);
        }
        default: {
            printf("Odebrano sygnal\n");
        }
    }
}

int main(int argc, char *argv[]) {

    receive_signal(alamakota);
    while (1)
        pause();
}

