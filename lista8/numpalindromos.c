#include <stdio.h>

int imprime_vetor(int *vetor, int tam) {
    for (int i = 0; i < tam; i++) {
        printf("%d", vetor[i]);
    }
    printf("\n ");
}

int ehpalindromobinario(int n) {
    int vetor[1000];
    int count = 0;
    while (n > 0) {
        vetor[count++] = n % 2;
        n = n / 2;
    }
    for (int i = 0; i < count; i++) {
        if (vetor[count - i - 1] != vetor[i]) {
            return 0;
        }
    }
    return 1;
}

int ehpalindromo(int n) {
    int vetor[10000];
    int count = 0;
    while (n > 0) {
        vetor[count++] = n % 10;
        n = n / 10;
    }
    for (int i = 0; i < count; i++) {
        if (vetor[count - i - 1] != vetor[i]) {
            return 0;
        }
    }
    return 1;
}

int numpalindromos(void) {
    int n;
    scanf("%d", &n);
    while (n--) {
        int m1, m2;
        scanf("%d %d", &m1, &m2);
        long long soma = 0, qtd = 0;
        for (int i = m1; i <= m2; i++) {
            if (i%2 == 0) {
                if (ehpalindromo(i) && ehpalindromobinario(i)){
                    qtd += 1;
                    soma += i;
                }
            }
        }
        printf("%d %d\n", soma, qtd);
    }
}

int main() {
    return numpalindromos();
}
