#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <memory.h>

#define ala 3

char *text;

int num = 1;

int delta = 1;

int tmp = 1;

int backwards = 1;

int max_num;

void print_text();

void print_text_backwards();

void sighandler(int signum) {
    switch (signum) {
        case SIGINT: {
            printf("Odebrano sygnał SIGINT\n");
            exit(0);
        }
        case SIGTSTP: {
            printf("Odebrano sygnał SIGTSTP\n");
            if (backwards == 0) {
                for (int i = 0; i < num; i++)
                    print_text();
            } else {
                for (int i = 0; i < num; i++)
                    print_text_backwards();
            }
            if (tmp == 0) {
                backwards = 1;
            } else if (tmp == 1) {
                backwards = 0;
            } else {
                num += delta;
                if (num > max_num) {
                    delta = -1;
                    num -= 2;
                } else if (num == 0) {
                    delta = 1;
                    num += 2;
                }
            }
            tmp = (tmp + 1) % 3;
            break;
        }
        default:
            break;
    }
    return;
}

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Trolololo");
        exit(1);
    }
    text = argv[1];
    max_num = atoi(argv[2]);
    if (max_num == 0) {
        printf("trolololo");
        exit(1);
    }
    print_text();
    do {
        signal(SIGINT, sighandler);
        struct sigaction abc;
        abc.sa_handler = sighandler;
        sigaction(SIGTSTP, &abc, NULL);
        pause();
    } while (1);
}

void print_text_backwards() {
    for (long i = strlen(text) - 1; i >= 0; i--)
        printf("%c", text[i]);
    printf("\n");
}

void print_text() {
    printf("%s\n", text);
}