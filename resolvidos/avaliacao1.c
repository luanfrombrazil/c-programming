int loteria()
{
    int aposta[6];
    int sorteados[6];
    int acertos = 0;
    for (short i = 0; i < 6; i++)
    {
        scanf("%d", &aposta[i]);
    }
    for (short i = 0; i < 6; i++)
    {
        scanf("%d", &sorteados[i]);
        for (short j = 0; j < 6; j++)
        {
            if (aposta[j] == sorteados[i])
            {
                acertos++;
            }
        }
    }
    if (acertos == 3)
    {
        printf("terno\n");
    }
    else if (acertos == 4)
    {
        printf("quadra\n");
    }
    else if (acertos == 5)
    {
        printf("quina\n");
    }
    else if (acertos == 6)
    {
        printf("sena\n");
    }
    else
    {
        printf("azar\n");
    }
}

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

int financeiro()
{
    int num_casos;
    scanf("%d", &num_casos);
    while (num_casos--)
    {
        float valor_mes;
        float media = 0;
        for (short i = 0; i < 12; i++)
        {
            scanf("%f", &valor_mes);
            media += valor_mes;
        }
        media /= 12;
        printf("$%.2f\n", media+0.0005);
    }
    return 0;
}
