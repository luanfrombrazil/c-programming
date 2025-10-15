#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define VALORMAXIMO 15;

int **matriz_atual = NULL;
int **matriz_transposta = NULL;
int tamanho_matriz_atual = 0;

void calcularTransposta() {
    if (matriz_atual == NULL || tamanho_matriz_atual == 0) {
        return;
    }

    matriz_transposta = (int **) malloc(tamanho_matriz_atual * sizeof(int *));
    for (int i = 0; i < tamanho_matriz_atual; i++) {
        matriz_transposta[i] = (int *) malloc(tamanho_matriz_atual * sizeof(int));
    }

    for (int i = 0; i < tamanho_matriz_atual; i++) {
        for (int j = 0; j < tamanho_matriz_atual; j++) {
            matriz_transposta[j][i] = matriz_atual[i][j];
        }
    }
}

void multiplicar() {
    if (matriz_atual == NULL)
        return;

    int n = tamanho_matriz_atual;

    int **resultado = (int **) malloc(n * sizeof(int *));
    if (resultado == NULL) {
        printf("Erro ao alocar memoria para a matriz da multiplicar");
    }
    for (int i = 0; i < n; i++) {
        resultado[i] = (int *) malloc(n * sizeof(int));
        if (resultado[i] == NULL) {
            for (int j = 0; j < i; j++)
                free(resultado[j]);
            free(resultado);
            printf("Erro ao alocar memoria para a matriz da multiplicar");
            return;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < n; k++) {
                resultado[i][j] += matriz_atual[i][k] * matriz_atual[j][k];
            }
        }
    }
    matriz_atual = resultado;
}

void alocarMatriz(int n, int inicializar) {
    srand((unsigned) time(NULL));
    matriz_atual = (int **) malloc(n * sizeof(int *));
    if (matriz_atual == NULL) {
        printf("Erro: Falha ao alocar array de ponteiros\n");
        return;
    }
    for (int i = 0; i < n; i++) {
        matriz_atual[i] = (int *) malloc(n * sizeof(int));
        if (matriz_atual[i] == NULL) {
            printf("Erro: Falha ao alocar linha %d\n", i);
            for (int j = 0; j < i; j++) {
                free(matriz_atual[j]);
            }
            free(matriz_atual);
            matriz_atual = NULL;
            return;
        }
        if (inicializar) {
            for (int j = 0; j < n; j++) {
                matriz_atual[i][j] = rand() % VALORMAXIMO;
            }
        }
    }
    tamanho_matriz_atual = n;
}

void desalocarMatriz() {
    if (matriz_atual == NULL) {
        return;
    }
    for (int i = 0; i < tamanho_matriz_atual; i++) {
        free(matriz_atual[i]);
    }
    for (int i = 0; i < tamanho_matriz_atual; i++) {
        free(matriz_transposta[i]);
    }
    free(matriz_atual);
    free(matriz_transposta);
    matriz_transposta = NULL;
    matriz_atual = NULL;
    tamanho_matriz_atual = 0;
}

void imprimirTransposta() {
    for (int i = 0; i < tamanho_matriz_atual; i++) {
        for (int j = 0; j < tamanho_matriz_atual; j++) {
            printf("%d ", matriz_transposta[i][j]);
        }
        printf("\n");
    }
}

void imprimirMatriz() {
    for (int i = 0; i < tamanho_matriz_atual; i++) {
        for (int j = 0; j < tamanho_matriz_atual; j++) {
            printf("%d ", matriz_atual[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int opcao;
    int n;
    int executando = 1;
    int inicializar; // usar int para scanf

    while (executando) {
        printf("\n--- Gerenciamento de Matriz ---\n");
        printf("1. Alocar matriz\n");
        printf("2. Desalocar matriz\n");
        printf("3. Imprimir matriz\n");
        printf("4. Imprimir transporta\n");
        printf("5. Criar matriz transposta\n");
        printf("6. Multiplicar matriz pela transposta\n");
        printf("7. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                if (matriz_atual != NULL) {
                    printf("Ja existe uma matriz alocada. Desaloque-a primeiro.\n");
                } else {
                    printf("Digite o tamanho N para a matriz N x N: ");
                    scanf("%d", &n);
                    if (n > 0) {
                        printf("Deseja inicializar a matriz? (1-Sim/0-Nao): ");
                        scanf("%d", &inicializar);
                        alocarMatriz(n, inicializar ? 1 : 0);
                        if (matriz_atual != NULL) {
                            printf("Matriz %d x %d alocada com sucesso.\n", n, n);
                            if (inicializar) {
                                printf("Matriz inicializada numeros aleatorios.\n");
                            }
                        } else {
                            printf("Falha ao alocar a matriz.\n");
                        }
                    } else {
                        printf("Tamanho invalido.\n");
                    }
                }
                break;
            case 2:
                if (matriz_atual == NULL) {
                    printf("Nenhuma matriz alocada para desalocar.\n");
                } else {
                    desalocarMatriz();
                    printf("Matriz desalocada com sucesso.\n");
                }
                break;
            case 3:
                if (matriz_atual == NULL) {
                    printf("Nenhuma matriz alocada para imprimir.\n");
                } else {
                    printf("Matriz atual:\n");
                    imprimirMatriz();
                }
                break;
            case 4:
                if (matriz_transposta == NULL) {
                    printf("Nenhuma matriz transposta alocada para imprimir.\n");
                } else {
                    printf("Matriz transposta:\n");
                    imprimirTransposta();
                }
                break;
            case 5:
                if (matriz_atual == NULL) {
                    printf("Nenhuma matriz alocada para transpor.\n");
                } else if (matriz_transposta == NULL) {
                    calcularTransposta(matriz_atual);
                } else {
                    printf("Matriz transposta já existe. Desaloque primeiro. (Opcao 2)\n");
                }
                break;
            case 6:
                if (matriz_atual == NULL) {
                    printf("Nenhuma matriz alocada para multiplicacao.\n");
                } else {
                    multiplicar();
                    printf("Multiplicacao realizada com sucesso.\n");
                }
                break;
            case 7:
                if (matriz_atual != NULL) {
                    printf("Desalocando matriz antes de sair...\n");
                    desalocarMatriz();
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