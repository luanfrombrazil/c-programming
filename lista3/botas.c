#include <stdio.h>

int botas(void)
{
    int i, n;
    scanf("%d", &n);
    int caixaDeBotas[30][2] = {0};
    for (i = 0; i < n; i++)
    {
        int numero;
        char lado;
        scanf("%d %c", &numero, &lado);
        numero -= 30;
        if (lado == 'E')
            caixaDeBotas[numero][1]++;
        else
            caixaDeBotas[numero][0]++;
    }
    int pares = 0;
    for (i = 0; i <= 30; i++)
    {
        pares += (caixaDeBotas[i][0] < caixaDeBotas[i][1]) ? caixaDeBotas[i][0] : caixaDeBotas[i][1];
    }
    printf("%d\n", pares);
    return 0;
}

int main() {
    return botas();
} 