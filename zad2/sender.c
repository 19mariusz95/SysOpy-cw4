#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void send_signal(int p);

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("troloolo");
        exit(1);
    }

    int ala = atoi(argv[1]);

    if (ala == 0) {
        printf("trolololo");
        exit(1);
    }

    int p;
    scanf("%d", &p);

    for (int i = 0; i < ala; i++) {
        send_signal(p);
    }

    return 0;
}

void send_signal(int p) {
    union sigval s;
    sigqueue(p, SIGUSR1, s);
}