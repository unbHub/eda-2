#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

void insere_inicio (celula *le, int x) {
    celula *novo;
    novo = (celula*)malloc(sizeof(celula));
    novo->dado = x;
    novo->prox = le->prox;
    le->prox = novo;
}

void insere_antes (celula *le, int x, int y) {
    celula *p, *q, *novo;
    novo = malloc(sizeof(celula));
    novo->dado = x;
    p = le;
    q = le->prox;
    while (q != NULL && q->dado != y) {
        p = q;
        q = q->prox;
    }
    novo->prox = q;
    p->prox = novo;
}