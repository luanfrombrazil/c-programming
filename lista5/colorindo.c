#include <stdio.h>

void imprime_matriz(int n, int m, int matriz[n][m]) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            printf("%d\t", matriz[i][j]);
        }
        printf("\n");
    }
}

void colorir(int n, int m, int matriz[n][m], int x, int y, int *pintados) {
    matriz[x][y] = 2;
    (*pintados)++;

    if (x - 1 >= 0 && matriz[x - 1][y] == 0) {
        colorir(n, m, matriz, x - 1, y, pintados);
    }
    if (y - 1 >= 0 && matriz[x][y - 1] == 0) {
        colorir(n, m, matriz, x, y - 1, pintados);
    }
    if (y + 1 < m && matriz[x][y + 1] == 0) {
        colorir(n, m, matriz, x, y + 1, pintados);
    }
    if (x + 1 < n && matriz[x + 1][y] == 0) {
        colorir(n, m, matriz, x + 1, y, pintados);
    }
    if (x + 1 < n && y + 1 < m && matriz[x + 1][y + 1] == 0) {
        colorir(n, m, matriz, x + 1, y + 1, pintados);
    }
    if (x - 1 >= 0 && y - 1 >= 0 && matriz[x - 1][y - 1] == 0) {
        colorir(n, m, matriz, x - 1, y - 1, pintados);
    }
    if (x - 1 >= 0 && y + 1 < m && matriz[x - 1][y + 1] == 0) {
        colorir(n, m, matriz, x - 1, y + 1, pintados);
    }
    if (x + 1 < n && y - 1 >= 0 && matriz[x + 1][y - 1] == 0) {
        colorir(n, m, matriz, x + 1, y - 1, pintados);
    }
}

int colorindo() {
    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);
    int matriz[n][m];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matriz[i][j] = 0;

    int aux_x;
    int aux_y;
    while (k--) {
        scanf("%d %d", &aux_x, &aux_y);
        matriz[aux_x - 1][aux_y - 1] = 1;
    }
    int quantos = 0;
    colorir(n, m, matriz, x - 1, y - 1, &quantos);
    printf("%d", quantos);
    return 0;
}

int main() {
    return colorindo();
} 