#include <stdio.h>

int loteria()
{
    int aposta[6];
    int sorteados[6];
    int acertos = 0;
    for (short i = 0; i < 6; i++)
    {
        scanf("%d", &aposta[i]);
    }
    for (short i = 0; i < 6; i++)
    {
        scanf("%d", &sorteados[i]);
        for (short j = 0; j < 6; j++)
        {
            if (aposta[j] == sorteados[i])
            {
                acertos++;
            }
        }
    }
    if (acertos == 3)
    {
        printf("terno\n");
    }
    else if (acertos == 4)
    {
        printf("quadra\n");
    }
    else if (acertos == 5)
    {
        printf("quina\n");
    }
    else if (acertos == 6)
    {
        printf("sena\n");
    }
    else
    {
        printf("azar\n");
    }
}

int main() {
    return loteria();
} 