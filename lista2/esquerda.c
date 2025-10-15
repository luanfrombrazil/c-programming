#include <stdio.h>

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

int main() {
    esquerda();
    return 0;
} 