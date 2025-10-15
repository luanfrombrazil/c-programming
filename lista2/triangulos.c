#include <math.h>
#include <stdio.h>

int triangulos(void)
{
    int a,b,c;
    scanf("%d %d %d",&a, &b, &c);
    while (a!=0 || b!=0 || c!=0)
    {
        double faltante;
        if (a==-1)
        {
            faltante = sqrt(c*c-b*b);
        }
        if (b==-1)
        {
            faltante = sqrt(c*c-a*a);
        }
        if (c==-1)
        {
            faltante = sqrt(a*a+b*b);
        }
        double deno = 1;
        double decimal = modf(faltante, &deno);
        if (decimal == 0.000)
        {
            printf("%.0f\n",faltante);
        }else
        {
            printf("%.3f\n",faltante-0.0005);
        }
        scanf("%d %d %d",&a, &b, &c);
    }
}

int main() {
    triangulos();
    return 0;
} 