//
// Created by student on 31/03/16.
//

#ifndef ZAD2_KSIADZ2_H
#define ZAD2_KSIADZ2_H

#include <bits/signum.h>
#include <signal.h>
#include <zconf.h>

#define MYSIG1 SIGRTMIN+3
#define MYSIG2 SIGRTMIN+4

void receive_signal(void (*fun)(int, siginfo_t *, void *)) {
    struct sigaction ala;
    ala.sa_sigaction = fun;
    ala.sa_flags = SA_SIGINFO;
    sigset_t alina;
    sigfillset(&alina);
    ala.sa_mask = alina;
    sigaction(MYSIG1, &ala, NULL);
    sigaction(MYSIG2, &ala, NULL);
}

#endif //ZAD2_KSIADZ2_H
