#include <stdlib.h>

typedef struct no {
    int chave;
    struct no *esq, *dir;
} no;

no *maximo (no *r) {
    while (r->dir != NULL) r = r->dir;
    return r;
}
