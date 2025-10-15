#include <stdio.h>

int letras()
{
    char letra;
    scanf("%c", &letra);
    char palavra[1001];
    float palavras_totais = 0;
    float palavras_com_letra = 0;

    while (scanf("%s", palavra) == 1)
    {
        palavras_totais++;
        for (int i = 0; palavra[i] != 0; i++)
        {
            if (palavra[i] == letra)
            {
                palavras_com_letra++;
                break;
            }
        }
    }    

    if (palavras_totais==0){
        printf("0.0");
        return 0;
    }

    float porcentagem = (palavras_com_letra / palavras_totais) * 100;
    printf("%.1f\n", porcentagem);
    return 0;
}

int main() {
    return letras();
} 