#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

#define ala 3

char *path;

int num = 1;

int delta = 1;

int tmp = 1;

int backwards = 1;

int max_num;

void print_poem();

void print_poem_backwards();

FILE *get_file();

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
                    print_poem();
            } else {
                for (int i = 0; i < num; i++)
                    print_poem_backwards();
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
    path = argv[1];
    max_num = atoi(argv[2]);
    if (max_num == 0) {
        printf("trolololo");
        exit(1);
    }
    print_poem();
    do {
        signal(SIGINT, sighandler);
        signal(SIGTSTP, sighandler);
        pause();
    } while (1);
}

void print_poem_backwards() {
    FILE *file = get_file();
    char alamakota[ala + 1];
    long tmp;
    fseek(file, 0, SEEK_END);
    long current, previous;
    previous = ftell(file);
    fseek(file, -ala, SEEK_CUR);
    tmp = fread(&alamakota, 1, ala, file);
    fseek(file, -tmp, SEEK_CUR);
    alamakota[tmp] = '\0';
    current = ftell(file);
    while (current < previous && tmp > 0) {
        for (long i = tmp - 1; i >= 0; i--)
            printf("%c", alamakota[i]);
        previous = current;
        fseek(file, -ala, SEEK_CUR);
        current = ftell(file);
        tmp = fread(&alamakota, 1, ala, file);
        alamakota[tmp] = '\0';
        fseek(file, -tmp, SEEK_CUR);
    }
    printf("\n");
    fclose(file);
}

FILE *get_file() {
    FILE *file = fopen(path, "r+");
    if (file == NULL) {
        printf("Trololo");
        exit(1);
    }
    return file;
}

void print_poem() {
    FILE *file = get_file();
    char alamakota[ala + 1];
    long tmp;
    while ((tmp = fread(&alamakota, 1, ala, file)) > 0) {
        alamakota[tmp] = '\0';
        printf(alamakota);
    }
    printf("\n");
    fclose(file);
}