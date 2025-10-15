#include <stdio.h>
#include <stdlib.h>

void imprime_vetor(int *vetor,int tamanho_vetor) {
    for (int i = 0; i < tamanho_vetor; i++) {
        printf("%d",vetor[i]);
    }
    printf("\n");
}

int alienigena() {
    while (1) {
        int decimal;
        scanf("%d", &decimal);
        int alienal[100], i = 0;

        for (int i = 0;i<100;i++) {
            alienal[i] = 0;
        }
        if (decimal == 0) {
            return 0;
        }

        while (decimal != 0) {
            alienal[i] = decimal % 4;
            decimal = decimal / 4;
            i++;
        }

        for (int j = i - 1; j >= 0; j--) {
            switch (alienal[j]) {
                case 1:
                    printf("B");
                    continue;
                case 2:
                    printf("C");
                    continue;
                case 3:
                    printf("D");
                    continue;
                case 0:
                    printf("A");
                    continue;
                case 5:
                    printf("BCB");
                    continue;
                case 6:
                    printf("CBA");
                    continue;
                case 7:
                    printf("DAB");
                    continue;
                case 8:
                    printf("AAA");
                    continue;
            }
        }
        printf("\n");
    }
}

int main() {
    return alienigena();
} 