#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int colorindo()
{
    int n, m, x, y, k;
    scanf("%d %d %d %d %d", &n, &m, &x, &y, &k);

    return 0;
}

typedef struct
{
    char nome[50];
    int idade;
    float nota;
} aluno;

int gestao()
{
    int alunoCounter = 0;
    int letras[26] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    float notas_t = 0;
    while (1)
    {
        aluno *a = malloc(sizeof(aluno));
        if (scanf("%s\n%d\n%f", &a->nome, &a->idade, &a->nota) != 3)
        {
            break;
        }
        printf("Dados do aluno:\nNome: %s\nIdade: %d\nNota: %.2f\n\n", a->nome, a->idade, a->nota);
        letras[(((int)a->nome[0]) - 65)] += 1;
        notas_t += a->nota;
        alunoCounter++;

        free(a);
    }

    int maior[5] = {0, 0, 0, 0, 0};
    int num_maior = 0;
    int j = 0;

    for (int k = 0; k < 5; k++)
    {
        num_maior = 25;
        for (int i = 24; i >= 0; i--)
        {
            if (letras[i] >= letras[num_maior])
            {
                num_maior = i;
            }
        }
        if (letras[num_maior] != 0)
        {
            maior[j++] = num_maior + (letras[num_maior] * 26);
        }
        // printf("LETRA: %d, N OC:%d", num_maior, letras[num_maior]);
        letras[num_maior] = 0;
    }

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (i != j && maior[j] % 26 > maior[i]%26)
            {
                int aux = maior[j];
                maior[j] = maior[i];
                maior[i] = aux;
            }
        }
    }

    printf("Estatisticas Finais:\nTotal de alunos: %d\nMedia das notas: %.2f\n\n", alunoCounter, (notas_t / alunoCounter));
    printf("Top 5 letras mais frequentes:\n");
    int indice = 5;
    while (indice--)
    {
        if (maior[4 - indice] / 26)
        {
            printf("%c: %d (%.1f%%)\n", (char)(maior[4 - indice] % 26 + 65), maior[4 - indice] / 26, (float)((maior[4 - indice] / 26) * 100.0 / (float)alunoCounter));
        }
    }

    return 0;
}

int main()
{
    return gestao();
}