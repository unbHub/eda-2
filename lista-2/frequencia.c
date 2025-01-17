#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char character;
    int frequency;
} CharFreq;

int compare(const void *a, const void *b) {
    CharFreq *cf1 = (CharFreq *)a;
    CharFreq *cf2 = (CharFreq *)b;

    if (cf1->frequency != cf2->frequency) {
        return cf1->frequency - cf2->frequency; // Ordem crescente por frequencia
    }
    return cf1->character - cf2->character; // Ordem crescente por valor ASCII
}

int main() {
    char line[1001];
    int firstOutput = 1;

    while (fgets(line, sizeof(line), stdin)) {
        int frequencies[128] = {0};
        int length = strlen(line);

        // Remove o caractere de nova linha, se presente
        if (line[length - 1] == '\n') {
            line[length - 1] = '\0';
            length--;
        }

        // Conta as frequências dos caracteres
        for (int i = 0; i < length; i++) {
            frequencies[(int)line[i]]++;
        }

        // Conta os caracteres únicos
        int uniqueCount = 0;
        for (int i = 0; i < 128; i++) {
            if (frequencies[i] > 0) {
                uniqueCount++;
            }
        }

        // Cria o array de estruturas para ordenar
        CharFreq *charFreqs = (CharFreq *)malloc(uniqueCount * sizeof(CharFreq));
        int index = 0;
        for (int i = 0; i < 128; i++) {
            if (frequencies[i] > 0) {
                charFreqs[index].character = i;
                charFreqs[index].frequency = frequencies[i];
                index++;
            }
        }

        qsort(charFreqs, uniqueCount, sizeof(CharFreq), compare);

        if (!firstOutput) {
            printf("\n");
        }
        firstOutput = 0;

        for (int i = 0; i < uniqueCount; i++) {
            printf("%d %d\n", (int)charFreqs[i].character, charFreqs[i].frequency);
        }

        free(charFreqs);
    }

    printf("\n");
    return 0;
}
