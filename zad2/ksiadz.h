//
// Created by student on 28/03/16.
//

#ifndef ZAD2_KSIADZ_H
#define ZAD2_KSIADZ_H

#include <bits/signum.h>
#include <signal.h>
#include <zconf.h>

void receive_signal(void (*fun)()) {
    signal(SIGUSR1, fun);
    struct sigaction ala;
    ala.sa_handler = fun;
    sigaction(SIGUSR2, &ala, NULL);
}

void send_signal(int p, int signal, union sigval s) {
    sigqueue(p, signal, s);
}

#endif //ZAD2_KSIADZ_H
