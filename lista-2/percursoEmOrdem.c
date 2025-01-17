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

void em_ordem(no *raiz) {
    if (raiz == NULL) return;

    pilha *p = cria_pilha(100);
    no *atual = raiz;

    while (atual != NULL || !pilha_vazia(p)) {

        while (atual != NULL) {
            empilha(p, atual);
            atual = atual->esq;
        }

        atual = desempilha(p);
        printf("%d ", atual->dado);

        atual = atual->dir;
    }

    free(p->elementos);
    free(p);
}
