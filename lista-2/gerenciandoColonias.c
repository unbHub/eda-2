#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PRIME 2097152 // Tamanho da tabela hash (próximo a 2^21)

// Estrutura para tabela hash global
typedef struct HashNode {
    int id;                // Identificação do formigueiro
    char alimento[11];     // Nome do alimento
    struct HashNode *next; // Encadeamento para tratar colisões
} HashNode;

HashNode *hash_table[PRIME]; // Tabela hash global

// Função de hash FNV-1a (incremental para id e alimento)
unsigned int fnv1a_hash(int id, const char *alimento) {
    unsigned int hash = 2166136261u; // Offset basis
    // Hash do id
    hash ^= (unsigned int)id;
    hash *= 16777619u;
    // Hash do alimento
    while (*alimento) {
        hash ^= (unsigned char)(*alimento);
        hash *= 16777619u;
        alimento++;
    }
    return hash % PRIME;
}

// Verifica se a combinação (id, alimento) já existe
int ja_entregue(int id, const char *alimento) {
    unsigned int index = fnv1a_hash(id, alimento);
    HashNode *current = hash_table[index];
    while (current) {
        if (current->id == id && strcmp(current->alimento, alimento) == 0) {
            return 1; // Combinação já existe
        }
        current = current->next;
    }
    return 0;
}

// Adiciona uma nova combinação (id, alimento)
void adicionar(int id, const char *alimento) {
    unsigned int index = fnv1a_hash(id, alimento);
    HashNode *new_node = malloc(sizeof(HashNode));
    if (!new_node) {
        fprintf(stderr, "Erro: falha ao alocar memória.\n");
        exit(1);
    }
    new_node->id = id;
    strcpy(new_node->alimento, alimento);
    new_node->next = hash_table[index];
    hash_table[index] = new_node;
}

int main() {
    char linha[128];

    // Processa entrada até EOF
    while (fgets(linha, sizeof(linha), stdin)) {
        int id;
        char alimento[11];
        sscanf(linha, "%d %10s", &id, alimento);

        // Verifica se já foi entregue
        if (ja_entregue(id, alimento)) {
            printf("%d\n", id); // Duplicata encontrada
        } else {
            adicionar(id, alimento); // Adiciona ao hash
        }
    }

    // Libera memória
    for (int i = 0; i < PRIME; i++) {
        HashNode *current = hash_table[i];
        while (current) {
            HashNode *tmp = current;
            current = current->next;
            free(tmp);
        }
    }

    return 0;
}
