#include <stdio.h>

int bakugan(void)
{
    int r;
    while (scanf("%d", &r))
    {
        if (r == 0)
            return 0;

        int bakugan[2][r];
        int pontos_m = 0;
        int pontos_l = 0;
        for (short i = 0; i < r; i++)
        {
            scanf("%d", &bakugan[0][i]);
            pontos_m += bakugan[0][i];
        }

        for (short i = 0; i < r; i++)
        {
            scanf("%d", &bakugan[1][i]);
            pontos_l += bakugan[1][i];
        }

        for (short i = 2; i < r; i++)
        {
            if (bakugan[0][i] == bakugan[0][i - 1] && bakugan[0][i - 1] == bakugan[0][i - 2])
            {
                if (bakugan[1][i] == bakugan[1][i - 1] && bakugan[1][i - 1] == bakugan[1][i - 2])
                {   
                    break;
                }
                else
                {
                    pontos_m += 30;
                    break;
                }
            }
            else
            {
                if (bakugan[1][i] == bakugan[1][i - 1] && bakugan[1][i - 1] == bakugan[1][i - 2])
                {
                    pontos_l += 30;
                    break;
                }
            }
        }

        if (pontos_m > pontos_l)
            printf("M\n");
        else if (pontos_l > pontos_m)
            printf("L\n");
        else
            printf("T\n");
    }
}

int main() {
    return bakugan();
} 