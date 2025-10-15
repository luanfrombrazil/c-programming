#include <stdio.h>
#include <stdlib.h>

int livro() {
    int q,d,p;
    while (scanf("%d %d %d",&q, &d, &p)==3) {
        int total_paginas = d*p*q/(p-q);
        if (total_paginas==1)
            printf("%d pagina\n",total_paginas);
        else
            printf("%d paginas\n",total_paginas);
    }
}

int main() {
    return livro();
} 