#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INIT_SIZE 10

void realoca_memoria(char ***vetor, int *tamanho) {
    *tamanho *= 2;
    *vetor = realloc(*vetor, (*tamanho) * sizeof(char *));
    if (*vetor == NULL) {
        printf("Erro de alocação de memória!\n");
        exit(1);
    }
}

int main(void) {
    char entrada[120];
    char STR[100];
    char comando[10];

    int tamanho_alteracoes = INIT_SIZE;
    int tamanho_desfeitas = INIT_SIZE;

    char **alteracoes = malloc(tamanho_alteracoes * sizeof(char *));
    char **desfeitas = malloc(tamanho_desfeitas * sizeof(char *));
    
    if (alteracoes == NULL || desfeitas == NULL) {
        printf("Erro de alocação de memória!\n");
        return 1;
    }

    int cont = 0, cont_desfeitas = 0;

    while (fgets(entrada, sizeof(entrada), stdin)) {
        if (sscanf(entrada, "%s %[^\n]", comando, STR) == 2) {
            if (strcmp(comando, "inserir") == 0) {
                if (cont >= tamanho_alteracoes) {
                    realoca_memoria(&alteracoes, &tamanho_alteracoes);
                }
                alteracoes[cont] = strdup(STR);
                cont++;
            }
        } else if (sscanf(entrada, "%s", comando) == 1) {
            if (strcmp(comando, "desfazer") == 0) {
                if (cont > 0) {
                    cont--;
                    if (cont_desfeitas >= tamanho_desfeitas) {
                        realoca_memoria(&desfeitas, &tamanho_desfeitas);
                    }
                    desfeitas[cont_desfeitas] = alteracoes[cont];
                    cont_desfeitas++;
                } else {
                    if (cont_desfeitas >= tamanho_desfeitas) {
                        realoca_memoria(&desfeitas, &tamanho_desfeitas);
                    }
                    desfeitas[cont_desfeitas] = strdup("NULL");
                    cont_desfeitas++;
                }
            }
        }
    }

    for (int i = 0; i < cont_desfeitas; i++) {
        printf("%s\n", desfeitas[i]);
        free(desfeitas[i]);
    }

    for (int i = 0; i < cont; i++) {
        free(alteracoes[i]);
    }

    free(alteracoes);
    free(desfeitas);

    return 0;
}