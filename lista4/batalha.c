#include <stdio.h>

int imprime_tabuleiro(int largura, int altura, int tabuleiro[altura][largura])
{
    printf("\n");
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            printf("%d", tabuleiro[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int encontra_barco(int largura, int altura, int tabuleiro[altura][largura], int x, int y, short totalmente_dest)
{
    if (tabuleiro[x][y] == 1)
    {
        totalmente_dest = 0;
    }

    tabuleiro[x][y] += 3;

    if (x - 1 >= 0 && tabuleiro[x - 1][y] != 0 && tabuleiro[x - 1][y] < 3)
    {
        totalmente_dest = encontra_barco(largura, altura, tabuleiro, x - 1, y, totalmente_dest);
    }
    if (y - 1 >= 0 && tabuleiro[x][y - 1] != 0 && tabuleiro[x][y - 1] < 3)
    {
        totalmente_dest = encontra_barco(largura, altura, tabuleiro, x, y - 1, totalmente_dest);
    }
    if (x < largura - 1 && tabuleiro[x + 1][y] != 0 && tabuleiro[x + 1][y] < 3)
    {
        totalmente_dest = encontra_barco(largura, altura, tabuleiro, x + 1, y, totalmente_dest);
    }
    if (y < altura - 1 && tabuleiro[x][y + 1] != 0 && tabuleiro[x][y + 1] < 3)
    {
        totalmente_dest = encontra_barco(largura, altura, tabuleiro, x, y + 1, totalmente_dest);
    }

    return totalmente_dest;
}

int batalha(void)
{
    int altura, largura;
    scanf("%d %d", &altura, &largura);
    int tabuleiro[altura][largura];

    for (int i = 0; i < altura; i++)
    {
        char frase[largura + 1];
        scanf("%s", frase);
        for (int j = 0; j < largura; j++)
        {
            if ((int)frase[j] == 35)
            {
                tabuleiro[i][j] = 1;
            }
            else
            {
                tabuleiro[i][j] = 0;
            }
        }
    }

    int tiros;
    scanf("%d", &tiros);
    for (int i = 0; i < tiros; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);

        if (tabuleiro[x - 1][y - 1] == 1)
        {
            tabuleiro[x - 1][y - 1]++;
        }
    }
    int destruidos = 0;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            short total_dest = 0;
            if (tabuleiro[i][j] == 1)
            {
                encontra_barco(largura, altura, tabuleiro, i, j, 0);
            }
            if (tabuleiro[i][j] == 2)
            {
                total_dest = encontra_barco(largura, altura, tabuleiro, i, j, 1);
            }

            if (total_dest == 1)
                destruidos++;
        }
    }
    printf("%d", destruidos);
}

int main() {
    batalha();
    return 0;
} 