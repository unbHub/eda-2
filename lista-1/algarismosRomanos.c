#include <stdio.h>

int main(void) {
    int n;
    char *romanos[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    int arabicos[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
    
    scanf("%d", &n);

    int vet[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &vet[i]);
    }

    for (int i = 0; i < n; i++) {
        int indice = (sizeof(arabicos) / sizeof(arabicos[0])) - 1;
        while (vet[i] > 0) {
            if (vet[i] >= arabicos[indice]) {
                printf("%s", romanos[indice]);
                vet[i] -= arabicos[indice];
            } else {
                indice--;
            }
        }
        printf("\n");
    }

    return 0;
}