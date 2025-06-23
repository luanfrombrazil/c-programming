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

int botas(void)
{
    int i, n;
    scanf("%d", &n);
    int caixaDeBotas[30][2] = {0};
    for (i = 0; i < n; i++)
    {
        int numero;
        char lado;
        scanf("%d %c", &numero, &lado);
        numero -= 30;
        if (lado == 'E')
            caixaDeBotas[numero][1]++;
        else
            caixaDeBotas[numero][0]++;
    }
    int pares = 0;
    for (i = 0; i <= 30; i++)
    {
        pares += (caixaDeBotas[i][0] < caixaDeBotas[i][1]) ? caixaDeBotas[i][0] : caixaDeBotas[i][1];
    }
    printf("%d\n", pares);
    return 0;
}

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

int copa(void)
{
    int t, n;
    while (scanf("%d %d", &t, &n) == 2)
    {

        int total = 0;
        for (short i = 0; i < t; i++)
        {   
            int pontos_jogo;
            char nome[10];
            scanf("%s %d", &nome,&pontos_jogo);
            total += pontos_jogo;
        }
        int empates = 3*n - total; 
        printf("%d",empates);
    }
    return 0;
}

int ajuda(void)
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        int vetor[26] = {0};
        int qtd_incorrect =0;
        int qtd_correct = 0;
        int tempo_total = 0;

        for (int i = 0; i < n; i++){
            int caso, tempo;
            char tentativa[9];
            scanf(" %c %d %s", &caso, &tempo, &tentativa);
            if (tentativa[0] == 105)
            {
                vetor[caso - 65]++;
            }
            if (tentativa[0] == 99)
            {
                qtd_correct++;
                qtd_incorrect += vetor[caso - 65];
                tempo_total = tempo;
            }
        }
        tempo_total += 20*qtd_incorrect;
        printf("%d %d\n", qtd_correct, tempo_total);
        scanf("%d", &n);
    }
}

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