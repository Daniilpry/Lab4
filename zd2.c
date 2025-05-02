#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main() {
    int xa = 1024 * 1024;
    int xb = 2048;
    int num = xa * xb;

    printf("xa = %d, xb = %d\n", xa, xb);
    printf("num (результат множення) = %d\n", num);

    void* ptr = malloc(num);
    if (ptr == NULL) {
        perror("malloc");
        printf("Не вдалося виділити %zu байт (num інтерпретовано як %zu).\n", (size_t)num, (size_t)num);
    } else {
        printf("malloc успішно виділив %d байт\n", num);
        free(ptr);
    }

    return 0;
}
