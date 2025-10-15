#include <stdio.h>

int quadrado_magico()
{
    int n;
    scanf("%d", &n);
    int q[n][n];
    int numero_magico = 0;
    short eh_magico;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &q[i][j]);
        }
        numero_magico += q[i][i];
    }

    for (int i = 0; i < n; i++)
    {
        int soma_colunas = 0;
        int soma_linhas = 0;
        int soma_diagonal_p = 0;
        int soma_diagonal_s = 0;
        for (int j = 0; j < n; j++)
        {
            soma_colunas += q[i][j];
            soma_linhas += q[j][i];
            soma_diagonal_p += q[j][j];
            soma_diagonal_s += q[n - 1 - j][j];
        }
        if (numero_magico != soma_colunas || numero_magico != soma_linhas || numero_magico != soma_diagonal_p || numero_magico != soma_diagonal_s)
        {
            printf("-1\n");
            return 0;
        }
    }

    printf("%d\n", numero_magico);
    return 0;
}

int main() {
    return quadrado_magico();
} 