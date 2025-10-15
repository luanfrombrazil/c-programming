#include <stdio.h>

int asdkhbayadspalindromo() {
    char risada[51];
    char palindromo[51];
    scanf("%s", risada);
    int n=0;

    for (int i = 0; risada[i] != 0; i++) {
        if (risada[i] == 'a' || risada[i] == 'e' || risada[i] == 'i' || risada[i] == 'o' || risada[i] == 'u') {
            palindromo[n++] = risada[i];
        }
    }

    for (int i = 0; i < n; i++) {
        if (palindromo[i] != palindromo[n-1-i]) {
            printf("N");
            return 0;
        }
    }
    printf("S");
    return 0;
}

int main() {
    return asdkhbayadspalindromo();
} 