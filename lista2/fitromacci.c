#include <stdio.h>

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

int main() {
    return fitromacci();
} 