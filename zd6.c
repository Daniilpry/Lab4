#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("=== realloc(NULL, size) ===\n");
    void* ptr1 = realloc(NULL, 100);
    if (ptr1) {
        printf("realloc(NULL, 100) = %p (успішно, як malloc)\n", ptr1);
        free(ptr1);
    } else {
        perror("realloc (NULL, 100)");
    }

    printf("\n=== realloc(non-null, 0) ===\n");
    void* ptr2 = malloc(100);
    if (!ptr2) {
        perror("malloc");
        return 1;
    }
    void* result = realloc(ptr2, 0);
    printf("realloc(ptr, 0) = %p (має бути NULL, памʼять звільнено)\n", result);

    return 0;
}
