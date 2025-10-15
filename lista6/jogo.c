#include <stdio.h>

int jogo() {
    int j, r;
    scanf("%d %d", &j, &r);
    int jogadores[500];
    for (int i = 0; i < 500; i++) {
        jogadores[i] = 0;
    }

    for (int i = 0; i < r; i++) {
        for (int k = 0; k < j; k++) {
            int pontos;
            scanf("%d", &pontos);
            jogadores[k] += pontos;
        }
    }

    int maior = 0;
    for (int i = 1; i < j; i++) {
        if (jogadores[i] >= jogadores[maior]) {
            maior = i;
        }
    }
    printf("%d", maior+1);
    return 0;
}

int main() {
    return jogo();
} 