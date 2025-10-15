#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

int *vetor_atual = NULL;
int tamanho_vetor_atual = 0;

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

void alocarVetor(int n, int inicializar) {
    // Aloca o vetor
    srand((unsigned) time(NULL));
    vetor_atual = (int *) malloc(n * sizeof(int));
    if (vetor_atual == NULL) {
        printf("Erro: Falha ao alocar vetor\n");
        return;
    }
    if (inicializar) {
        for (int i = 0; i < n; i++) {
            vetor_atual[i] = rand(); // Isso forcara a alocacao física
        }
    }
    tamanho_vetor_atual = n;
}

void desalocarVetor() {
    if (vetor_atual == NULL) {
        return;
    }
    // Libera o vetor
    free(vetor_atual);
    // Reseta as variaveis
    vetor_atual = NULL;
    tamanho_vetor_atual = 0;
}

void redimensionarVetor(int novo_tamanho) {
    if (vetor_atual == NULL) {
        printf("Erro: Nenhum vetor alocado para redimensionar\n");
        return;
    }
    // Aloca um novo vetor com o novo tamanho
    int *novo_vetor = (int *) malloc(novo_tamanho * sizeof(int));
    if (novo_vetor == NULL) {
        printf("Erro: Falha ao alocar novo vetor\n");
        return;
    }
    // Copia os elementos do vetor antigo para o novo
    int elementos_para_copiar = (novo_tamanho < tamanho_vetor_atual) ? novo_tamanho : tamanho_vetor_atual;
    for (int i = 0; i < elementos_para_copiar; i++) {
        novo_vetor[i] = vetor_atual[i];
    }
    // Libera o vetor antigo
    free(vetor_atual);
    // Atualiza as variaveis
    vetor_atual = novo_vetor;
    tamanho_vetor_atual = novo_tamanho;
}

void imprimirVetor() {
    if (vetor_atual == NULL) {
        printf("Nenhum vetor alocado.\n");
        return;
    }
    printf("\nVetor atual (%d elementos):\n", tamanho_vetor_atual);
    for (int i = 0; i < tamanho_vetor_atual; i++) {
        printf("%d ", vetor_atual[i]);
    }
    printf("\n");
}

void ordenarVetor() {
    printf("Vetor ordenado!\n");
    quicksort(vetor_atual, 0, tamanho_vetor_atual - 1);
    printf("Vetor ordenado!\n");
}

int main() {
    int opcao;
    int n;
    int executando = 1;
    int inicializar;
    while (executando) {
        printf("\n--- Gerenciamento de Vetor ---\n");
        printf("1. Alocar vetor\n");
        printf("2. Desalocar vetor\n");
        printf("3. Redimensionar vetor\n");
        printf("4. Imprimir vetor\n");
        printf("5. Ordenar vetor\n");
        printf("6. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                if (vetor_atual != NULL) {
                    printf("Ja existe um vetor alocado. Desaloque-o primeiro(Opcao 2).\n");
                } else {
                    printf("Digite o tamanho do vetor: ");
                    scanf("%d", &n);
                    if (n > 0) {
                        printf("Deseja inicializar o vetor? (1-Sim/0-Nao): ");
                        scanf("%d", &inicializar);
                        alocarVetor(n, inicializar);
                        if (vetor_atual != NULL) {
                            printf("Vetor de tamanho %d alocado com sucesso.\n", n);
                            if (inicializar) {
                                printf("Vetor inicializado numeros aleatorios.\n");
                            }
                        } else {
                            printf("Falha ao alocar o vetor.\n");
                        }
                    } else {
                        printf("Tamanho invalido.\n");
                    }
                }
                break;
            case 2:
                if (vetor_atual == NULL) {
                    printf("Nenhum vetor alocado para desalocar.\n");
                } else {
                    desalocarVetor();
                    printf("Vetor desalocado com sucesso.\n");
                }
                break;
            case 3:
                if (vetor_atual == NULL) {
                    printf("Nenhum vetor alocado para redimensionar.\n");
                } else {
                    printf("Digite o novo tamanho do vetor: ");
                    scanf("%d", &n);
                    if (n > 0) {
                        redimensionarVetor(n);
                        printf("Vetor redimensionado com sucesso.\n");
                    } else {
                        printf("Tamanho invalido.\n");
                    }
                }
                break;
            case 4:
                imprimirVetor();
                break;
            case 5:
                ordenarVetor();
                break;
            case 6:
                if (vetor_atual != NULL) {
                    printf("Desalocando vetor antes de sair...\n");
                    desalocarVetor();
                }
                executando = 0;
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }
    return 0;
} 