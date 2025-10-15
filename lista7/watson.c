#include <stdio.h>

void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionar(int *vetor, int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }
    trocar(&vetor[i + 1], &vetor[fim]);
    return i + 1;
}

void quicksort(int *vetor, int inicio, int fim) {
    if (inicio < fim) {
        int indice_pivo = particionar(vetor, inicio, fim);
        quicksort(vetor, inicio, indice_pivo - 1);
        quicksort(vetor, indice_pivo + 1, fim);
    }
}

void imprime_vetor(int *vetor,int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d",vetor[i]);
    }
    printf("\n");
}

int watson() {
    int num_suspeitos;
    do {
        scanf("%d", &num_suspeitos);
        if (num_suspeitos == 0)
            return 0;

        int vetor[num_suspeitos];
        int original[num_suspeitos];

        for (int j = 0; j < num_suspeitos; j++) {
            scanf("%d", &vetor[j]);
            original[j] = vetor[j];
        }

        quicksort(vetor, 0, num_suspeitos - 1);

        int mais_suspeito = vetor[num_suspeitos-2];
        for (int i = 0; i < num_suspeitos; i++) {
            if (mais_suspeito == original[i]) {
                printf("%d\n",i+1);
                break;
            }
        }
    }while (num_suspeitos);
}

int main() {
    return watson();
} 