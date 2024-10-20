#include <stdio.h>

/*

Férias de Julho
Promoção: 01/07 - 01/08
diária menor para quem chegar cedo e vai aumentando a cada dia

- dia 1: D reais, ou seja, paga 31 * D reais.
- Aumenta A reais por dia.
- dia 2: D + A reais, ou seja, paga 30 * (D + A)
- dia 3: D + 2 * A reais, ou seja, paga 29 * (D + 2 * A)
- dia 4: D + 3 * A reais, ou seja, paga 28 * (D + 3 * A)
...

*/

int main(void) {
    int diaria, aumento, dia, valorTotal;

    scanf("%d", &diaria);
    scanf("%d", &aumento);
    scanf("%d", &dia);

    valorTotal = (31 - (dia - 1)) * (diaria + (dia - 1) * aumento);

    printf("%d\n", valorTotal);

    return 0;
}