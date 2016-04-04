#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <memory.h>

char *text;

int num = 1;

int delta = 1;

int tmp = 0;

int backwards = 0;

int max_num;

void print_text();

void print_text_backwards();

void print();

void sighandler(int signum) {
    switch (signum) {
        case SIGINT: {
            printf("Odebrano sygnał SIGINT\n");
            exit(0);
        }
        case SIGTSTP: {
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
        printf("Not enough arguments\n");
        exit(1);
    }
    text = argv[1];
    max_num = atoi(argv[2]);
    if (max_num == 0) {
        printf("wrong 2nd argument");
        exit(1);
    }
    signal(SIGINT, sighandler);
    struct sigaction abc;
    abc.sa_handler = sighandler;
    sigaction(SIGTSTP, &abc, NULL);
    while (1) {
        print();
        sleep(1);
    }
}

void print() {
    if (backwards == 0) {
        for (int i = 0; i < num; i++)
            print_text();
    } else {
        for (int i = 0; i < num; i++)
            print_text_backwards();
    }
    printf("\n");
}

void print_text_backwards() {
    for (long i = strlen(text) - 1; i >= 0; i--)
        printf("%c", text[i]);
    printf("\n");
}

void print_text() {
    printf("%s\n", text);
}