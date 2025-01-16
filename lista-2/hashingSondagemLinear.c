#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int *tb; // tabela hash
  int M;   // tamanho da tabela hash
  int N;   // total de chaves presentes na tabela
} TH;

// Função fornecida que retorna o próximo tamanho primo
int aumentaTamanho(int M);

// Função hash modular
#define hash(ch, M) ((ch) % (M))

// Função auxiliar para redimensionar a tabela hash
void redimensionaTabela(TH *h) {
    int novoTamanho = aumentaTamanho(h->M);
    int *novaTabela = malloc(novoTamanho * sizeof(int));
    
    // Inicializa a nova tabela com -1 (vazio)
    for (int i = 0; i < novoTamanho; i++) {
        novaTabela[i] = -1;
    }

    // Reinsere as chaves da tabela antiga
    for (int i = 0; i < h->M; i++) {
        if (h->tb[i] != -1) {
            int novaPos = hash(h->tb[i], novoTamanho);
            while (novaTabela[novaPos] != -1) {
                novaPos = (novaPos + 1) % novoTamanho;
            }
            novaTabela[novaPos] = h->tb[i];
        }
    }

    free(h->tb);
    h->tb = novaTabela;
    h->M = novoTamanho;
}

// Função para inserir uma chave na tabela hash
void THinsere(TH *h, int ch) {
    // Verifica se a chave já existe
    if (THbusca(h, ch)) return;

    // Redimensiona a tabela se necessário
    if (h->N > h->M / 2) {
        redimensionaTabela(h);
    }

    // Calcula a posição inicial
    int pos = hash(ch, h->M);

    // Sondagem linear para encontrar posição livre
    while (h->tb[pos] != -1) {
        pos = (pos + 1) % h->M;
    }

    // Insere a chave na posição encontrada
    h->tb[pos] = ch;
    h->N++;
}

// Função para buscar uma chave na tabela hash
int THbusca(TH *h, int ch) {
    int pos = hash(ch, h->M);

    // Sondagem linear para busca
    for (int i = 0; i < h->M; i++) {
        if (h->tb[pos] == -1) {
            return 0; // Chave não encontrada
        }
        if (h->tb[pos] == ch) {
            return 1; // Chave encontrada
        }
        pos = (pos + 1) % h->M;
    }

    return 0;
}

// Função para remover uma chave da tabela hash
int THremove(TH *h, int ch) {
    int pos = hash(ch, h->M);

    // Sondagem linear para encontrar a chave
    for (int i = 0; i < h->M; i++) {
        if (h->tb[pos] == -1) {
            return -1; // Chave não encontrada
        }
        if (h->tb[pos] == ch) {
            h->tb[pos] = -1; // Remove a chave
            h->N--;

            // Reinsere as chaves subsequentes para evitar falhas de busca
            for (int j = (pos + 1) % h->M; h->tb[j] != -1; j = (j + 1) % h->M) {
                int chaveReinserir = h->tb[j];
                h->tb[j] = -1;
                h->N--;
                THinsere(h, chaveReinserir);
            }

            return 0; // Chave removida
        }
        pos = (pos + 1) % h->M;
    }

    return -1; // Chave não encontrada
}
