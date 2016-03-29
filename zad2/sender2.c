#include <stdio.h>
#include <stdlib.h>
#include "ksiadz.h"

int ala = 0;
int ala2;
union sigval s;


void fun(int singal) {
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

void fun2() {

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

    printf("%d\n", getpid());
    fflush(stdout);

    int p;
    printf("podaj pid\n");
    scanf("%d", &p);

    for (int i = 0; i < ala2; i++) {
        send_signal(p, SIGUSR1, s);
        receive_signal(fun2);
    }
    send_signal(p, SIGUSR2, s);

    receive_signal(fun);
    while (1) {
        pause();
    }
}