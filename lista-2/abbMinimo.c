#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *minimo (no *r) {
    while (r->esq != NULL) r = r->esq;
    return r;
}
