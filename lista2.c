#include <math.h>
#include <stdbool.h>
#include <stdio.h>

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



void esquerda(void)
{
    int input=1;
    scanf("%d",&input);
    while(input!=0)
    {
        int final=0;
        char string[input];
        scanf("%s",&string);
        char posicao[4] = {'N','L','S','O'};
        for(int i=0;i<input;i++)
        {
            if (string[i]=='E')
            {
                final--;
            }else
            {
                final++;
            }
        }
        final = final%4;
        if(final<0)
        {
            final = 4+final;
        }
        printf("%c",posicao[final]);

        scanf("%d",&input);
    }

}
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

int numtriangulares(void){
    int i,s;
    while (scanf("%d", &s)==1&& &s>0){
        i=1;
        while((i*(i+1)*(i+2))<=s){               
            if((i*(i+1)*(i+2)==s)){
                printf("%d %d %d\n",i,i+1,i+2);
                break;
            }else{
                                    
            }        
            i++;
        }
        if((i*(i+1)*(i+2))>s){
            printf("mensagem falsa\n");            
        }
    }
    return 0;
}

int fitromacci(void){        
    int n,k,inst;
    scanf("%i",&inst);
    while(inst--){
        scanf("%i %i", &k,&n);
        long long numeros[n];
        for (int i = 0; i < n; i++)
        {
            if(i<k){
                numeros[i] = 1;
            }else if(i==k){
                numeros[i]=k;
            }else{
                numeros[i]= numeros[i-1]*2 - numeros[i-k-1];
            }
        }
        printf("%lld\n",numeros[n-1]);
    }        
}

int equacao(void)
{
    int a,b,c;
    //scanf("%i %i %i",&a,&b,&c);
    //int contador = 4;
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
        //scanf("%i %i %i",&a,&b,&c);
    }
    return 0;
}


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