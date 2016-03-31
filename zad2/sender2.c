#include <stdio.h>
#include <stdlib.h>
#include "ksiadz.h"

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
        printf("troloolo");
        exit(1);
    }

    ala2 = atoi(argv[1]);

    if (ala2 == 0) {
        printf("trolololo");
        exit(1);
    }

    pid_t pid;
    char line[100];
    FILE *cmd = popen("pidof catcher", "r");
    if (cmd == NULL) {
        printf("trololo");
        exit(1);
    }
    fgets(line, 100, cmd);
    unsigned long p = strtoul(line, NULL, 10);
    if (p == ULONG_MAX || p == 0) {
        printf("trololololo");
        exit(1);
    }
    pclose(cmd);
    pid = (pid_t) p;

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