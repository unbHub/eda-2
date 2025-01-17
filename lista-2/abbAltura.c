#include <stdlib.h>

typedef struct no {
   int chave;
   struct no *esq, *dir;
} no;

int altura (no *r) {
    if (r == NULL) return 0;
    int he = altura(r->esq);
	int hd = altura(r->dir);
	if (he > hd) return he + 1;
    else return hd + 1;
}
