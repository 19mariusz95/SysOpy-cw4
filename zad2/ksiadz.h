//
// Created by student on 28/03/16.
//

#ifndef ZAD2_KSIADZ_H
#define ZAD2_KSIADZ_H

#include <bits/signum.h>
#include <signal.h>
#include <zconf.h>

void receive_signal(void (*fun)(int, siginfo_t *, void *)) {
    struct sigaction ala;
    ala.sa_sigaction = fun;
    ala.sa_flags = SA_SIGINFO;
    sigset_t alina;
    sigfillset(&alina);
    ala.sa_mask = alina;
    sigaction(SIGUSR1, &ala, NULL);
    sigaction(SIGUSR2, &ala, NULL);
}

int send_signal(int p, int signal, union sigval s) {
    int result = sigqueue(p, signal, s);
    if (result != 0)
        printf("Error");
    return result;
}

#endif //ZAD2_KSIADZ_H
