#include <stdio.h>
#include <stdlib.h>

int energia() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int a1, c1, a2, c2;
        scanf("%d %d %d %d",&a1,&c1,&a2,&c2);
        double crescimento = (c2 - c1)*1.0/(a2-a1)*1.0 - 0.0045;
        printf("%.2f\n",crescimento);
    }
}

int main() {
    return energia();
} 