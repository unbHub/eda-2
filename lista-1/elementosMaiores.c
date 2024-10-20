#include <stdio.h>

int main(void) {
    int N, encontrou = 0;
    long long int soma = 0, media;

    scanf("%d", &N);

    long int vet[N];

    for (int i = 0; i < N; i++) {
        scanf("%ld", &vet[i]);
        soma += vet[i];
    }

    media = soma / N;

    for (int i = 0; i < N; i++) {
        if (vet[i] > media) {
            printf("%ld ", vet[i]);
            encontrou = 1;
        }
    }

    if (!encontrou) {
        printf("0");
    }

    printf("\n");
    return 0;
}