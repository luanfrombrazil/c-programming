#include <stdio.h>

int escada() {
    while (1) {
        int n;
        scanf("%d", &n);
        if (!n) return 0;

        int segundos = 0;
        int tempo_anterior = 0;
        int t;
        while (n--) {
            scanf("%d", &t);
            segundos += 10;
            if (t - tempo_anterior < 10 && tempo_anterior !=0) {
                segundos -= 10 - (t - tempo_anterior);
            }
            tempo_anterior = t;
        }
        printf("%d\n", segundos);
    }
}

int main() {
    return escada();
} 