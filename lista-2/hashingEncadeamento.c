#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    int dado;
    struct celula *prox;
} celula;

typedef struct {
    celula *tb; // tabela hash (vetor de listas encadeadas)
    int M;      // tamanho da tabela hash
    int N;      // total de chaves presentes na tabela
} TH;

// Função auxiliar: Calcula o índice da tabela hash usando hash modular
int hash_modular(int chave, int M) {
    return chave % M;
}

// Insere uma chave na tabela hash
void THinsere(TH *h, int ch) {
    int idx = hash_modular(ch, h->M); // Índice da tabela
    celula *p = &h->tb[idx]; // Ponteiro para a lista no índice calculado

    // Verifica se a chave já existe na lista encadeada
    celula *aux = p->prox;
    while (aux != NULL) {
        if (aux->dado == ch) return; // Chave duplicada, não insere
        aux = aux->prox;
    }

    // Insere no início da lista encadeada
    celula *novo = (celula *)malloc(sizeof(celula));
    if (novo == NULL) return; // Verifica se a memória foi alocada
    novo->dado = ch;
    novo->prox = p->prox;
    p->prox = novo;
    h->N++; // Incrementa o total de chaves na tabela
}

// Remove uma chave da tabela hash
int THremove(TH *h, int ch) {
    int idx = hash_modular(ch, h->M); // Índice da tabela
    celula *p = &h->tb[idx]; // Ponteiro para a lista no índice calculado

    // Percorre a lista para encontrar a chave
    celula *ant = p;
    celula *atual = p->prox;
    while (atual != NULL) {
        if (atual->dado == ch) {
            ant->prox = atual->prox; // Remove o nó da lista
            free(atual); // Libera a memória do nó removido
            h->N--; // Decrementa o total de chaves na tabela
            return 0; // Sucesso na remoção
        }
        ant = atual;
        atual = atual->prox;
    }

    return -1; // Chave não encontrada
}

// Busca uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int idx = hash_modular(ch, h->M); // Índice da tabela
    celula *p = h->tb[idx].prox; // Ponteiro para a lista no índice calculado

    // Percorre a lista para encontrar a chave
    while (p != NULL) {
        if (p->dado == ch) return 1; // Chave encontrada
        p = p->prox;
    }

    return 0; // Chave não encontrada
}
