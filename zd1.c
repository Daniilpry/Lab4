#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <errno.h>

int main() {
    size_t max_size = (size_t)-1;  // або UINT64_MAX
    printf("Спроба виділити %zu байт пам’яті...\n", max_size);

    void *ptr = malloc(max_size);
    if (ptr == NULL) {
        perror("malloc");
        printf("Не вдалося виділити %zu байт.\n", max_size);
    } else {
        printf("Успішно виділено %zu байт!\n", max_size);
        free(ptr);
    }

    return 0;
}

