#include <math.h>
#include <stdbool.h>
#include <stdio.h>

int n, m;
int matrizadj[2000][2000];
int visitado[2000];

void busca(int v) {
    visitado[v] = 1;
    for (int i = 0; i < n; i++) {
        if (matrizadj[v][i] && !visitado[i]) {
            busca(i);
        }
    }
}

int conexo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visitado[j] = 0;
        busca(i);
        for (int j = 0; j < n; j++) {
            if (!visitado[j]) return 0;
        }
    }
    return 1;
}

int irevir(void){
    while(scanf("%d %d", &n,&m)==2 && n!=0 && m!=0){    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        matrizadj[i][j] = 0;

    while(m--){
        int v, w, p;
        scanf("%d %d %d", &v, &w, &p);
        v--; w--;
        matrizadj[v][w] = 1;
        if (p == 2) matrizadj[w][v] = 1;
    }

    printf(conexo() ? "1\n" : "0\n");
    }
    return 0;
}

int main() {
    return irevir();
} 