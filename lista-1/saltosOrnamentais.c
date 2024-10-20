#include <stdio.h>

void bubbleSort(float vet[], int tam) {
    int i, j;
    float temp;
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
    float notaJuiz[7];
    float dificuldade;

    scanf("%f", &dificuldade);

    for (int i = 0; i < 7; i++) {
        scanf("%f", &notaJuiz[i]);
    }

    bubbleSort(notaJuiz, 7);

    float soma = 0;
    for (int i = 1; i < 6; i++) {
        soma += notaJuiz[i];
    }

    float media = soma / 5;

    printf("%.1f\n", media*dificuldade);

    return 0;
}