#include <stdio.h>
#include <stdlib.h>
#include "ksiadz.h"
#include "ksiadz3.h"

int ala = 0;
int ala2;
union sigval s;
int wait = 1;
int flaga = 1;


void fun(int singal, siginfo_t *info, void *cont) {
    switch (singal) {
        case SIGUSR1: {
            if (flaga) {
                wait = 0;
            } else {
                ala++;
                send_signal(info->si_pid, SIGUSR1, s);
            }
            break;
        }
        case SIGUSR2: {
            printf("Odebrano %d z %d", ala, ala2);
            exit(0);
        }
        default: {
        }
    }
}

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Not enough arguments\n");
        exit(1);
    }

    ala2 = atoi(argv[1]);

    if (ala2 == 0) {
        printf("Wrong 2nd argument\n");
        exit(1);
    }

    pid_t pid = get_catcher_pid("pidof catcher2");

    receive_signal(fun);

    for (int i = 0; i < ala2; i++) {
        send_signal(pid, SIGUSR1, s);
        while (wait);
        wait = 1;
    }
    flaga = 0;
    send_signal(pid, SIGUSR2, s);


    while (1) {
        pause();
    }
}