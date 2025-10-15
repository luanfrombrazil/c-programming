#include <stdio.h>

int handebol(void)
{
    int n, m;
    int contador = 0;
    scanf("%i %i", &n, &m);
    for (int k = 0; k < n; k++)
    {
        int emtodos = 1;
        int x;

        for (int i = 0; i < m; i++)
        {
            scanf("%d", &x);
            if (x == 0)
            {
                emtodos = 0;
            }
        }
        if (emtodos)
            contador++;
    }
    printf("%d", contador);
    return 0;
}

int main() {
    return handebol();
} 