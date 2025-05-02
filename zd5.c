#include <stdio.h>
#include <stdlib.h>

int main() {
    size_t size = 1024;
    char *ptr = malloc(size);
    if (!ptr) {
        perror("malloc");
        return 1;
    }

    for (int i = 0; i < size; i++)
        ptr[i] = 'A';

    printf("Спроба realloc на великий обсяг памʼяті...\n");

    // імітація помилки )
    size_t new_size = (size_t)-1;

    char *tmp = realloc(ptr, new_size);
    if (tmp == NULL) {
        perror("realloc");
        printf("realloc не вдалося. ptr все ще дійсний: %p\n", (void*)ptr);
        free(ptr);
    } else {
        ptr = tmp;
        free(ptr);
    }

    return 0;
}
