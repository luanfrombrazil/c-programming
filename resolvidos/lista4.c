
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

int labirinto(void)
{
    char linha[1000];
    while (scanf("%s", linha)==1)
    {
        //printf("%s",linha);
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




int relax(void)
{
    int l, a, xa, ya, xb, yb;
    scanf("%d %d\n%d %d\n%d %d", &l, &a, &xa, &ya, &xb, &yb);
    float luan = 0;
    float larissa = 0;
    float total = 0;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            double dist_luan = sqrt((double)(xa - i) * (xa - i) + (ya - j) * (ya - j));
            double dist_larissa = sqrt((double)((xb - i) * (xb - i) + (yb - j) * (yb - j)));
            if (dist_luan == dist_larissa) continue;
            dist_luan < dist_larissa ? luan++ : larissa++;
            total++;
        }
    }
    printf("%.9f %.9f\n", luan / total, larissa / total);
    return 0;
}



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







#include <math.h>

int mapas(void);

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









int n, m;
int matrizadj[2000][2000];
int visitado[2000];

void busca(int v) {
    visitado[v] = 1;
    for (int i = 0; i < n; i++) {
        if (matrizadj[v][i] && !visitado[i]) {
            busca(i);
        }
    }
}

int conexo() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) visitado[j] = 0;
        busca(i);
        for (int j = 0; j < n; j++) {
            if (!visitado[j]) return 0;
        }
    }
    return 1;
}

int irevir(void){
    while(scanf("%d %d", &n,&m)==2 && n!=0 && m!=0){    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        matrizadj[i][j] = 0;

    while(m--){
        int v, w, p;
        scanf("%d %d %d", &v, &w, &p);
        v--; w--;
        matrizadj[v][w] = 1;
        if (p == 2) matrizadj[w][v] = 1;
    }

    printf(conexo() ? "1\n" : "0\n");
    }
    return 0;
}
















int relax(void)
{
    int l, a, xa, ya, xb, yb;
    scanf("%d %d\n%d %d\n%d %d", &l, &a, &xa, &ya, &xb, &yb);
    double luan = 0;
    double larissa = 0;
    double total = 0;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            double dist_luan = sqrt((double)(xa - i) * (xa - i) + (ya - j) * (ya - j));
            double dist_larissa = sqrt((double)((xb - i) * (xb - i) + (yb - j) * (yb - j)));
            if (dist_luan == dist_larissa) continue;
            dist_luan < dist_larissa ? luan++ : larissa++;
            total++;
        }
    }
    printf("%.9lf %.9lf\n", luan / total, larissa / total);
    return 0;
}
















int mapas(void);

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

    if (x > 0 && tabuleiro[x - 1][y] != 0 && tabuleiro[x - 1][y] < 3)
    {
        totalmente_dest = encontra_barco(largura, altura, tabuleiro, x - 1, y, totalmente_dest);
    }
    if (y 0 && tabuleiro[x][y - 1] != 0 && tabuleiro[x][y - 1] < 3)
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
     imprime_tabuleiro(largura, altura, tabuleiro);
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
    imprime_tabuleiro(largura, altura, tabuleiro);
    int destruidos = 0;
    for (int i = 0; i < altura; i++)
    {
        for (int j = 0; j < largura; j++)
        {
            short total_dest = 0;
            printf("x: %d, y: %d\n",i,j);
            if (tabuleiro[i][j] == 1)
            {
                total_dest = encontra_barco(largura, altura, tabuleiro, i, j, 0);
            }
            if (tabuleiro[i][j] == 2)
            {
                total_dest = encontra_barco(largura, altura, tabuleiro, i, j, 1);
            }

            if (total_dest == 1)                
               destruidos++;
        }
    }
   printf("%d\n", destruidos);
}


#include <stdio.h>
#include <math.h>

int relax(void)
{
    long double l, a, xa, ya, xb, yb;
    scanf("%lf %lf\n%lf %lf\n%lf %lf", &l, &a, &xa, &ya, &xb, &yb);
    long double luan = 0;
    long double larissa = 0;
    long double total = 0;
    for (int i = 0; i <= l; i++)
    {
        for (int j = 0; j <= a; j++)
        {
            double dist_luan = sqrt((xa - i) * (xa - i) + (ya - j) * (ya - j));
            double dist_larissa = sqrt(((xb - i) * (xb - i) + (yb - j) * (yb - j)));
            if (dist_luan == dist_larissa)
            {
                //    luan++;
                //    larissa++;
                //    total += 2;
            }
            else
            {
                dist_luan < dist_larissa ? luan++ : larissa++;
                total++;
            };
        }
    }
    printf("%.9lf %.9lf\n", luan / total, larissa / total);
    return 0;
}

// int main(void)
// {
//     return relax();
// }