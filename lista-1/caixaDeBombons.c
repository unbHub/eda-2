#include <stdio.h>

// - Crocante: 5g amendoim, 25g chocolate branco e 20g chocolate ao leite
// - Misto: 25g chocolate branco e 25g chocolate ao leite
// - Tradicional: 50g chocolate ao leite

// - a gramas de amendoim
// - b gramas de chocolate branco
// - c gramas de chocolate ao leite

// - Especial: 30 crocantes
// - Predileta: 10 crocante e 20 misto
// - Sortida: 10 de cada tipo

int main(void) {
    int a, b, c;

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);

    int qtd_crocante = a / 5;
    if (qtd_crocante > b / 25) {
        qtd_crocante = b / 25;
    }

    if (qtd_crocante > c / 20) {
        qtd_crocante = c / 20;
    }
    b -= qtd_crocante * 25;
    c -= qtd_crocante * 20;


    int qtd_misto = b / 25;
    if (qtd_misto > c / 25) {
        qtd_misto = c / 25;
    }
    b -= qtd_misto * 25;
    c -= qtd_misto * 25;

    int qtd_tradicional = c / 50;

    int caixa_sortida = 0;
    while (qtd_crocante >= 10 && qtd_misto >= 10 && qtd_tradicional >= 10) {
        caixa_sortida++;
        qtd_crocante -= 10;
        qtd_misto -= 10;
        qtd_tradicional -= 10;
    }

    int caixa_predileta = 0;
    while (qtd_crocante >= 10 && qtd_misto >= 20) {
        caixa_predileta++;
        qtd_crocante -= 10;
        qtd_misto -= 20;
    }

    int caixa_especial = qtd_crocante / 30;
    qtd_crocante -= caixa_especial * 30;

    printf("%d %d %d\n", caixa_especial, caixa_predileta, caixa_sortida);

    return 0;
}