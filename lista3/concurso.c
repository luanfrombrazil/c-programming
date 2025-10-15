#include <stdio.h>

int concurso(void)
{
    int NUM_PALAVRAS, MAX_LINHAPAG, MAX_CARACTERES;
    scanf("%d %d %d", &NUM_PALAVRAS, &MAX_LINHAPAG, &MAX_CARACTERES);

    int n = NUM_PALAVRAS + 1;
    int caracteres_por_palavra[NUM_PALAVRAS];
    while (--n)
    {
        char palavra[70] = {0};
        scanf("%s", &palavra);
        short i;
        for (i = 0; palavra[i] != 0; i++)
            ;
        caracteres_por_palavra[NUM_PALAVRAS - n] = i;
    }

    int contador =0;
    int num_linha = 1;
    int total_de_paginas = 1;
    n = NUM_PALAVRAS + 1;
    while (--n)
    {
        if(contador + caracteres_por_palavra[NUM_PALAVRAS - n] > MAX_CARACTERES){

            if(num_linha+1>MAX_LINHAPAG){
                num_linha=1;
                total_de_paginas++;
            }else{
                num_linha++;
            }            
            contador = caracteres_por_palavra[NUM_PALAVRAS - n]+1;
        }else{
            contador += caracteres_por_palavra[NUM_PALAVRAS - n]+1;
        }
    }
    printf("%d",total_de_paginas);
    return 0;
}

int main() {
    return concurso();
} 