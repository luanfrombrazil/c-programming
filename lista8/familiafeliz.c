#include <stdio.h>

int familiafeliz() {
    int n;

    do {
        long long vetor[100000];
        for (n = 0; n < 20000; n++) {
            vetor[n] = 0;
        }
        scanf("%d", &n);
        if (!n) break;
        int count = 0;
        long long fatorial = 1;

        for (int i = 1; i <= n; i++) {

            while (i > 0) {
                vetor[count++] = n % 10;
                n = n / 10;
            }

            for (int j = 0; j <= n; j++) {

            }
        }
        vetor[count] = fatorial;

        for (int i = count; i >= 0; i--) {
            printf("%lld", vetor[i]);
        }
        printf("\n");
    } while (1);
    return 0;
}

int main() {
    return familiafeliz();
} 