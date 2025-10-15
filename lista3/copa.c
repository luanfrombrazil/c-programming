#include <stdio.h>

int copa(void)
{
    int t, n;
    while (scanf("%d %d", &t, &n) == 2)
    {

        int total = 0;
        for (short i = 0; i < t; i++)
        {   
            int pontos_jogo;
            char nome[10];
            scanf("%s %d", &nome,&pontos_jogo);
            total += pontos_jogo;
        }
        int empates = 3*n - total; 
        printf("%d",empates);
    }
    return 0;
}

int main() {
    return copa();
} 