#include <stdio.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

int remove_depois (celula *p) {
    if (p != NULL && p->prox != NULL) {
        celula *lixo = p->prox;
        p->prox = lixo->prox;
        free(lixo);
        return 1;
    } else {
        return 0;
    }
}

void remove_elemento (celula *le, int x) {
    celula *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL && q->dado != x) {
        p = q;
        q = q->prox;
    }
    if (q != NULL) {
        p->prox = q->prox;
        free(q);
    }
}

void remove_todos_elementos (celula *le, int x) {
    celula *p, *q;
    p = le;
    q = le->prox;
    while (q != NULL) {
        if (q->dado == x) {
            p->prox = q->prox;
            free(q);
            q = p->prox;
        } else {
            p = q;
            q = q->prox;
        }
    }
}