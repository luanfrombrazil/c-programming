#include <stdio.h>

int fase() {
    int n, k;
    scanf("%d\n%d", &n,&k);
    int pontuacao[n];
    for (int i = 0; i < n; i++) {
        scanf("%d",&pontuacao[i]);
    }
    int qtd_prox=0;
    for (int i = 0; i < n; i++) {
        if (qtd_prox>=k)
            break;
        int maior = pontuacao[0];
        for (int j = 1; j < n; j++) {
            if (pontuacao[j] > maior) {
                maior = pontuacao[j];
            }
        }
        for (int j = 0; j < n; j++) {
            if (pontuacao[j] == maior) {
                qtd_prox++;
                pontuacao[j] = 0;
            }
        }
    }
    printf("%d", qtd_prox);
}

int main() {
    return fase();
} 