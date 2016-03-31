#include <stdio.h>
#include <stdlib.h>
#include "ksiadz2.h"

int ala = 0;
int ala2;
union sigval s;


void fun(int singal, siginfo_t *info, void *cont) {
    if (singal == MYSIG1) {
        ala++;
    }
    else if (singal == MYSIG2) {
        printf("Odebrano %d z %d", ala, ala2);
        exit(0);
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
    FILE *cmd = popen("pidof catcher3", "r");
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

    for (int i = 0; i < ala2; i++) {
        send_signal(pid, MYSIG1, s);
    }
    send_signal(pid, MYSIG2, s);

    receive_signal(fun);
    while (1) {
        pause();
    }
}