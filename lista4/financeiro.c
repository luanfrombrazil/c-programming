#include <stdio.h>

int financeiro()
{
    int num_casos;
    scanf("%d", &num_casos);
    while (num_casos--)
    {
        float valor_mes;
        float media = 0;
        for (short i = 0; i < 12; i++)
        {
            scanf("%f", &valor_mes);
            media += valor_mes;
        }
        media /= 12;
        printf("$%.2f\n", media+0.0005);
    }
    return 0;
}

int main() {
    return financeiro();
} 