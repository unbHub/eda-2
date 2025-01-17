#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no *esq, *dir;
} no;

typedef struct pilha {
    no **elementos;
    int topo;
    int capacidade;
} pilha;

pilha *cria_pilha(int capacidade) {
    pilha *p = (pilha *)malloc(sizeof(pilha));
    p->elementos = (no **)malloc(capacidade * sizeof(no *));
    p->topo = -1; // Pilha vazia
    p->capacidade = capacidade;
    return p;
}

// Função auxiliar: verifica se a pilha está vazia
int pilha_vazia(pilha *p) {
    return p->topo == -1;
}

// Função auxiliar: empilha um nó
void empilha(pilha *p, no *n) {
    if (p->topo < p->capacidade - 1) {
        p->elementos[++p->topo] = n;
    }
}

// Função auxiliar: desempilha um nó
no *desempilha(pilha *p) {
    if (!pilha_vazia(p)) {
        return p->elementos[p->topo--];
    }
    return NULL;
}

void pos_ordem(no *raiz) {
    if (raiz == NULL) return;

    pilha *p1 = cria_pilha(100);
    pilha *p2 = cria_pilha(100);
    empilha(p1, raiz);

    while (!pilha_vazia(p1)) {
        no *atual = desempilha(p1);
        empilha(p2, atual);

        if (atual->esq != NULL) {
            empilha(p1, atual->esq);
        }
        if (atual->dir != NULL) {
            empilha(p1, atual->dir);
        }
    }

    while (!pilha_vazia(p2)) {
        no *atual = desempilha(p2);
        printf("%d ", atual->dado);
    }

    free(p1->elementos);
    free(p1);
    free(p2->elementos);
    free(p2);
}
