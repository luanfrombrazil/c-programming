#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int valor;
    int peso;
    struct node* next;
}node;

int invertendosetas() {
    int bibi = 0, bibika = 0;
    int c, s, a, b;
    scanf("%c %s %a %b", &c, &s, &a, &b);

    node* adjacencias = (node*)malloc(sizeof(node)*c);

    for (int i = 0; i < c; i++)
        adjacencias[i].valor = 0;

    while (s--) {
        int c1, c2;
        scanf("%d %d", &c1, &c2);
        node* atual = &adjacencias[c1];
        while (atual->next != NULL) {
            atual = atual->next;
        }

        atual->next = (node*)malloc(sizeof(node));
        atual->next->next = NULL;
        atual->next->valor = c2;
        atual->next->peso = 0;
    }

    if
    (bibi) {
        printf("Bibi: %d", bibi);
    } else if
    (bibika) {
        printf("Bibika: %d", bibika);
    } else {
        printf("Bibibika");
    }
}

int main() {
    invertendosetas();
    return 0;
} 