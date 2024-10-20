#include <stdio.h>

typedef struct {
    int ano;
    int semestre;
    int qtd_disciplinas;
    int maior_reprovacao[30];
    int max_reprovacoes;
    int qtd_maiores;
} Semestre;

void bubbleSort(int vet[], int tam) {
    int i, j, temp;
    for (i = tam - 1; i > 0; i--) {
        for (j = 0; j < i; j++) {
            if (vet[j] > vet[j + 1]) {
                temp = vet[j];
                vet[j] = vet[j + 1];
                vet[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    int total_disciplinas = 0, cont = 0;
    int cod_disciplina = 0, qtd_matriculados = 0, qtd_aprovados = 0;
    Semestre semestre[100];

    scanf("%d", &total_disciplinas);

    while (1) {
        if (scanf("%d", &semestre[cont].ano) == EOF) break;
        scanf("%d", &semestre[cont].semestre);
        scanf("%d", &semestre[cont].qtd_disciplinas);

        semestre[cont].max_reprovacoes = -1;
        semestre[cont].qtd_maiores = 0;

        for (int i = 0; i < semestre[cont].qtd_disciplinas; i++) {
            scanf("%d", &cod_disciplina);
            scanf("%d", &qtd_matriculados);
            scanf("%d", &qtd_aprovados);

            int reprovacoes = qtd_matriculados - qtd_aprovados;

            if (reprovacoes > semestre[cont].max_reprovacoes) {
                semestre[cont].max_reprovacoes = reprovacoes;
                semestre[cont].qtd_maiores = 1;
                semestre[cont].maior_reprovacao[0] = cod_disciplina;
            } else if (reprovacoes == semestre[cont].max_reprovacoes) {
                semestre[cont].maior_reprovacao[semestre[cont].qtd_maiores] = cod_disciplina;
                semestre[cont].qtd_maiores++;
            }
        }
        
        bubbleSort(semestre[cont].maior_reprovacao, semestre[cont].qtd_maiores);

        cont++;
    }

    for (int i = 0; i < cont; i++) {
        printf("%d/%d\n", semestre[i].ano, semestre[i].semestre);
        for (int j = 0; j < semestre[i].qtd_maiores; j++) {
            printf("%d ", semestre[i].maior_reprovacao[j]);
        }
        printf("\n\n");
    }

    return 0;
}