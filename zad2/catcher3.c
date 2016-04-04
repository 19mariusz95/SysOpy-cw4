#include <stdlib.h>
#include <stdio.h>
#include "ksiadz2.h"
#include "ksiadz3.h"

int ala2 = 0;
union sigval s;

void alamakota(int singal, siginfo_t *info, void *cont) {
    if (singal == MYSIG1) {
        ala2++;
    }
    else if (singal == MYSIG2) {
        for (int i = 0; i < ala2; i++) {
            send_signal(info->si_pid, MYSIG1, s);
        }
        send_signal(info->si_pid, MYSIG2, s);
        exit(0);
    }
}

int main(int argc, char *argv[]) {

    receive_signal(alamakota);
    while (1)
        pause();
}

