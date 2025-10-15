#include <stdio.h>

int fila() {
    int pessoas;
    long long total = 1;
    scanf("%d", &pessoas);
    while (pessoas) {
        total = 1;
        for (int i = pessoas; i > 3; i--) {
            total *= i;
            total %= 1000000009;
        }
        printf("%d\n", total);

        scanf("%d", &pessoas);
    }
    return 0;
}

int main() {
    return fila();
} 