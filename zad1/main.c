#include <stdlib.h>
#include <stdio.h>
#include <math.h>

#define ala 3

void print_poem(FILE *file);

void print_poem_backwards(FILE *file);

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Trolololo");
        exit(1);
    }
    char *path = argv[1];
    FILE *file = fopen(path, "r+");
    if (file == NULL) {
        printf("Trololo");
        exit(1);
    }
    print_poem(file);
    printf("\n");
    print_poem_backwards(file);
    return 0;
}

void print_poem_backwards(FILE *file) {
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

}

void print_poem(FILE *file) {
    char alamakota[ala + 1];
    long tmp;
    while ((tmp = fread(&alamakota, 1, ala, file)) > 0) {
        alamakota[tmp] = '\0';
        printf(alamakota);
    }
}