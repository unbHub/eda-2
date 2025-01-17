#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

void remover_antecessor(no *r) {
	no *max = r->esq;
	no *pai_max = r;
	while (max->dir != NULL) {
		pai_max = max;
		max = max->dir;
	}
	r->chave = max->chave;
	if (pai_max->dir == max) pai_max->dir = max->esq;
	else pai_max->esq = max->esq;
	free(max);
}

no *remover(no *r, int x) {
	if (r == NULL) return NULL;
	if (x < r->chave)
		r->esq = remover(r->esq, x);
	else if (x > r->chave)
		r->dir = remover(r->dir, x);
	// Encontrei x
	else {
		if (r->esq == NULL) {
            no *temp = r->dir;
            free(r);
            return temp;
        } else if (r->dir == NULL) {
            no *temp = r->esq;
            free(r);
            return temp;
        }
		else remover_antecessor(r);
	}
    return r;
}
