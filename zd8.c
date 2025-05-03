#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void test_allocation(const char* label, size_t size) {
    printf("=== %s ===\n", label);

    void* ptr = malloc(size);
    if (!ptr) {
        perror("malloc");
        return;
    }

    printf("malloc(%zu) успішно: %p\n", size, ptr);

    memset(ptr, 0, 1);
    printf("Успішно записано 1 байт у виділену памʼять\n");

    free(ptr);
    printf("Памʼять звільнено\n\n");
}

int main() {
    test_allocation("Малий блок (128 байт)", 128);

    test_allocation("Великий блок (1 ГБ)", 1024L * 1024 * 1024);

    test_allocation("Дуже великий блок (32 ГБ)", 32L * 1024 * 1024 * 1024);

    return 0;
}
