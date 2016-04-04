#include <stdio.h>
#include <stdlib.h>
#include "ksiadz.h"
#include "ksiadz3.h"

int ala = 0;
int ala2;
union sigval s;


void fun(int singal, siginfo_t *info, void *cont) {
    switch (singal) {
        case SIGUSR1: {
            ala++;
            break;
        }
        case SIGUSR2: {
            printf("Odebrano %d z %d", ala, ala2);
            exit(0);
        }
        default: {
            printf("Odebrano sygnal\n");
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

    pid_t pid = get_catcher_pid("pidof catcher");

    for (int i = 0; i < ala2; i++) {
        send_signal(pid, SIGUSR1, s);
    }
    send_signal(pid, SIGUSR2, s);

    receive_signal(fun);
    while (1) {
        pause();
    }
}