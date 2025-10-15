#include <stdio.h>

int ajuda(void)
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        int vetor[26] = {0};
        int qtd_incorrect =0;
        int qtd_correct = 0;
        int tempo_total = 0;

        for (int i = 0; i < n; i++){
            int caso, tempo;
            char tentativa[9];
            scanf(" %c %d %s", &caso, &tempo, &tentativa);
            if (tentativa[0] == 105)
            {
                vetor[caso - 65]++;
            }
            if (tentativa[0] == 99)
            {
                qtd_correct++;
                qtd_incorrect += vetor[caso - 65];
                tempo_total = tempo;
            }
        }
        tempo_total += 20*qtd_incorrect;
        printf("%d %d\n", qtd_correct, tempo_total);
        scanf("%d", &n);
    }
}

int main() {
    ajuda();
    return 0;
} 