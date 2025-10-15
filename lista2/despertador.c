#include <stdio.h>

void despertador(void)
{
    int h1,m1,h2,m2;
    while (h1!=0||m1!=0||h2!=0||m2!=0)
    {
        scanf("%d %d %d %d",&h1,&m1,&h2,&m2);

        int t1 = h1 * 60 + m1;
        int t2 = h2 * 60 + m2;

        if (t2 < t1) {
            t2 += 24 * 60;
        }

        int dif = t2 - t1;
        if (h1!=0||m1!=0||h2!=0||m2!=0)
        {
            printf("%d", dif);
        }
    }
}

int main() {
    despertador();
    return 0;
} 