#include <stdio.h>
#include <string.h>

#define MAX_NODES 52

int find_index(const char *infix, char target, int start, int end) {
    for (int i = start; i <= end; i++) {
        if (infix[i] == target) {
            return i;
        }
    }
    return -1;
}

void construct_postfix(const char *prefix, const char *infix, int start, int end, int *prefix_index, char *postfix, int *postfix_index) {
    if (start > end) {
        return;
    }

    char root = prefix[*prefix_index];
    (*prefix_index)++;

    int root_index = find_index(infix, root, start, end);

    construct_postfix(prefix, infix, start, root_index - 1, prefix_index, postfix, postfix_index);

    construct_postfix(prefix, infix, root_index + 1, end, prefix_index, postfix, postfix_index);

    postfix[*postfix_index] = root;
    (*postfix_index)++;
}

int main() {
    int C;
    scanf("%d", &C);

    while (C--) {
        int N; // Número de nodos
        char prefix[MAX_NODES + 1]; // Percurso prefixo
        char infix[MAX_NODES + 1];  // Percurso infixo
        char postfix[MAX_NODES + 1]; // Percurso pós-fixo

        scanf("%d %s %s", &N, prefix, infix);

        int prefix_index = 0;
        int postfix_index = 0;

        // Reconstrói o percurso pós-fixo
        construct_postfix(prefix, infix, 0, N - 1, &prefix_index, postfix, &postfix_index);

        // Adiciona o terminador de string
        postfix[postfix_index] = '\0';

        // Imprime o percurso pós-fixo
        printf("%s\n", postfix);
    }

    return 0;
}
