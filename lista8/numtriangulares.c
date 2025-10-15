#include <stdio.h>

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

int main() {
    return numtriangulares();
} 