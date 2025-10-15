#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int caracter;
    struct node *prox;
} node;

int imprime_lista(node *atual) {
    while (atual->prox != NULL) {
        printf("%c", atual->caracter);
        atual = atual->prox;
    }
    printf("\n");
}

int imprime_vetor(char *vetor) {
    while (*vetor != '\0') {
        printf("%c", *vetor++);
    }
    printf("\n");
}

int guerra() {
    char *frase = malloc(sizeof(char) * 101);
    int chave;
    node *cabeca = malloc(sizeof(node));
    while (scanf("%s\n%d", frase, &chave) == 2) {
        int primos[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
        int chave_decrypt;

        for (int i = 0; i < 25; i++) {
            if (chave * primos[i] % 27 == 1) {
                chave_decrypt = primos[i];
                break;
            }
        }

        node* atual = cabeca;
        while ((int) *frase != 0) {
            atual->caracter = (int)*frase++;
            atual->prox = malloc(sizeof(node));
            atual = atual->prox;
        }

        atual->prox = NULL;
        atual = cabeca;

        while (atual != NULL) {
            atual->caracter = (atual->caracter - 65) * chave_decrypt % 27;
            if (atual->caracter == 26) {
                atual->caracter = 32;
            } else {
                atual->caracter += 65;
            }
            atual = atual->prox;
        }
        imprime_lista(cabeca);
    }
}

int main() {
    guerra();
    return 0;
} 