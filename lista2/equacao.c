#include <math.h>
#include <stdio.h>

int equacao(void)
{
    int a,b,c;
    while (scanf("%i %i %i",&a,&b,&c)==3)
    {
        if(a==0)
        {
            printf("Nao e uma equacao de grau 2\n");
            
        }else{
         printf("Equacao: %i(x2) + %i(x) + %i\n",a,b,c);
         int delta = b * b - 4 * a * c;
         if (delta > 0)
         {
             float raiz1= (-b + sqrt(delta))/2*a;
             float raiz2=(-b - sqrt(delta))/2*a;
             printf("Solucao com 2 raizes reais\n");
             printf("X1: %.1f\n",raiz1);
             printf("X2: %.1f\n",raiz2);
         }
         else if (delta == 0)
         {
             float raiz1= (-b + sqrt(delta))/2*a;
             printf("Solucao com 1 raiz real\n");
             printf("X1: %.1f\n",raiz1);
         }
         else
         {
             printf("Solucao com 0 raizes reais\n");
             printf("X1: Nao existe raiz real\n");
         }
        }        
    }
    return 0;
}

int main() {
    return equacao();
} 