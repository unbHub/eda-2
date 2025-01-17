#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORD_LENGTH 16
#define HASH_SIZE 65536

typedef struct Node {
    char word[MAX_WORD_LENGTH + 1];
    int count;
    struct Node *next;
} Node;

Node *hash_table[HASH_SIZE];

unsigned int hash_function(const char *word) {
    unsigned int hash = 0;
    while (*word) {
        hash = (hash * 31 + *word) % HASH_SIZE;
        word++;
    }
    return hash;
}

Node *find_or_create_node(const char *word) {
    unsigned int hash_index = hash_function(word);
    Node *current = hash_table[hash_index];

    while (current) {
        if (strcmp(current->word, word) == 0) {
            return current;
        }
        current = current->next;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));
    strcpy(new_node->word, word);
    new_node->count = 0;
    new_node->next = hash_table[hash_index];
    hash_table[hash_index] = new_node;

    return new_node;
}

int main() {
    char command[20];
    char word[MAX_WORD_LENGTH + 1];

    // Inicializa a tabela hash
    memset(hash_table, 0, sizeof(hash_table));

    while (scanf("%s %s", command, word) != EOF) {
        int cmd = atoi(command);
        Node *node = find_or_create_node(word);

        if (cmd == 1) {
            node->count++;
        } else if (cmd == 2) {
            printf("%d\n", node->count);
        } else if (cmd == 3) {
            node->count = 0;
        }
    }

    for (int i = 0; i < HASH_SIZE; i++) {
        Node *current = hash_table[i];
        while (current) {
            Node *temp = current;
            current = current->next;
            free(temp);
        }
    }

    return 0;
}

