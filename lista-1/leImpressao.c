#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void imprime(celula *le) {
    celula *p = le->prox;
    while (p != NULL) {
        printf("%d -> ", p->dado);
        p = p->prox;
    }
    printf("NULL\n");
}

void imprime_rec(celula *le) {
    if (le->prox != NULL) {
        printf("%d -> ", le->prox->dado);
        imprime_rec(le->prox);
    } else {
        printf("NULL\n");
    }
}
