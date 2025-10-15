#include <stdio.h>

int navalha_batal(void)
{
    int n, q;
    scanf("%d %d", &n, &q);
    int tabuleiro[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            tabuleiro[i][j] = 0;
        }
    }

    for (int i = 0; i < q; i++)
    {
        int x, y;
        scanf("%d %d", &x, &y);
        tabuleiro[x - 1][y - 1]++;
    }

    int qtd_total = 0;
    for (int i = 0; i < n; i++)
    {
        int espaco = 0;
        for (int j = 0; j < n; j++)
        {
            if (tabuleiro[i][j] == 0)
            {
                espaco++;
            }
            else if (espaco != 0)
            {
                while (espaco != 0)
                {
                    qtd_total += espaco--;
                }
            }
        }

        if (espaco != 0)
        {
            while (espaco != 0)
            {
                qtd_total += espaco--;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        int espaco = 0;
        for (int j = 0; j < n; j++)
        {
            if (tabuleiro[i][j] == 0)
            {
                espaco++;
            }
            else if (espaco != 0)
            {
                espaco--;
                while (espaco != 0)
                {
                    qtd_total += espaco--;
                }
            }
        }

        if (espaco != 0)
        {
            espaco--;
            while (espaco != 0)
            {
                qtd_total += espaco--;
            }
        }
    }
    printf("%d", qtd_total);
}

int main() {
    navalha_batal();
    return 0;
} 