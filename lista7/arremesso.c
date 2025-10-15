#include <stdio.h>

int arremesso() {
    int buraco, velocidade;
    while (1) {
        scanf("%d %d", &buraco, &velocidade);
        if (buraco == 0)
            return 0;
        int encontrado = 0;

        for (int i = velocidade; i > 0; i--) {
            int path = 0;
            encontrado = 0;
            for (int j = i; j > 0; j--) {
                for (int k = j; k > 0; k--) {
                    path += j;
                    if (path == buraco) {
                        encontrado = 1;
                        break;
                    }
                    if (path > buraco && encontrado ==0) {
                        break;
                    }
                }
                if (encontrado) break;
            }
            if (encontrado) break;
        }
        if (encontrado) {
            printf("possivel\n");
        }else{
            printf("impossivel\n");
        }
    }
}

int main() {
    return arremesso();
} 