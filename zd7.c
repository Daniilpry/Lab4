#include <stdlib.h>
#include <stdio.h>

struct sbar {
    int a;
    double b;
};

int main() {
    struct sbar *ptr, *newptr;

    ptr = calloc(1000, sizeof(struct sbar));
    if (!ptr) {
        perror("calloc");
        return 1;
    }

    newptr = reallocarray(ptr, 500, sizeof(struct sbar));
    if (!newptr) {
        perror("reallocarray");
        free(ptr); // стару пам’ять слід звільнити вручну
        return 1;
    }

    ptr = newptr;
    free(ptr);

    return 0;
}

