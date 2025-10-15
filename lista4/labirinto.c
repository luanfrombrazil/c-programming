#include <stdio.h>

int labirinto(void)
{
    char linha[1000];
    while (scanf("%s", linha)==1)
    {
        int quantidade = 0;
        int errada = 1;
        for (int i = 0; (int)linha[i] != 0; i++)
        {
            if ((int)linha[i] == 33)
            {
                printf("\n");
                quantidade=0;
            }
            else if ((int)linha[i] > 48 && (int)linha[i] <= 57)
            {
                quantidade += linha[i] - 48;
                errada=0;
            }
            else
            {
                while (quantidade)
                {
                    if ((int)linha[i] == 98)
                    {
                        printf(" ");
                        quantidade--;
                    }
                    else
                    {
                        printf("%c", linha[i]);
                        quantidade--;
                    }
                }
            }
        }
        if (errada)
        {
            printf("Entrada errada");
        }        
        printf("\n-------------\n");
    }

    return (0);
}

int main() {
    return labirinto();
} 