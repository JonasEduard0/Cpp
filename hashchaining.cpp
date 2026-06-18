#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Tamanho da tabela hash
#define HASH_TABLE_SIZE 7

// Estrutura da tabela hash
typedef struct {
    vector<int> table[HASH_TABLE_SIZE];
} hash_t;

// Função hash
int ctd_hash_key(int key) {

    // Método da divisão
    // Garante que o índice fique entre 0 e HASH_TABLE_SIZE-1
    return abs(key % HASH_TABLE_SIZE);
}

// Busca uma chave na tabela
int hash_search(hash_t* hash, int key) {

    // Calcula a posição onde a chave deveria estar
    int pos = ctd_hash_key(key);

    // Percorre a lista da posição calculada
    for (int valor : hash->table[pos]) {

        // Se encontrou a chave
        if (valor == key) {
            return 1;
        }
    }

    // Não encontrou
    return 0;
}

// Insere uma chave
void hash_insert(hash_t* hash, int key) {

    // Evita duplicidade
    if (hash_search(hash, key)) {
        return;
    }

    // Calcula posição
    int pos = ctd_hash_key(key);

    // Adiciona ao final da lista
    hash->table[pos].push_back(key);
}

// Remove uma chave
void hash_delete(hash_t* hash, int key) {

    // Calcula posição
    int pos = ctd_hash_key(key);

    // Percorre a lista
    for (auto it = hash->table[pos].begin();
         it != hash->table[pos].end();
         ++it) {

        // Encontrou a chave
        if (*it == key) {

            // Remove o elemento
            hash->table[pos].erase(it);

            return;
        }
    }
}

// Mostra toda a tabela hash
void hash_show(hash_t* hash) {

    cout << "\n===== TABELA HASH =====\n";

    // Percorre todas as posições
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {

        cout << i << " -> ";

        // Percorre os elementos daquela posição
        for (int valor : hash->table[i]) {
            cout << valor << " ";
        }

        cout << endl;
    }
}

// Retorna quantidade total de elementos
int hash_size(hash_t* hash) {

    int total = 0;

    // Soma o tamanho de cada lista
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        total += hash->table[i].size();
    }

    return total;
}

// Verifica se a tabela está vazia
int hash_empty(hash_t* hash) {

    return hash_size(hash) == 0;
}

// Remove todos os elementos
void hash_clear(hash_t* hash) {

    // Limpa todas as listas
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        hash->table[i].clear();
    }
}

// Calcula o fator de carga
float hash_load_factor(hash_t* hash) {

    int n = hash_size(hash);

    return (float)n / HASH_TABLE_SIZE;
}

// Mostra colisões
void hash_collisions(hash_t* hash) {

    int total = 0;

    cout << "\n===== COLISOES =====\n";

    // Percorre toda a tabela
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {

        // Se houver mais de um elemento
        if (hash->table[i].size() > 1) {

            cout << "Posicao " << i
                 << " possui "
                 << hash->table[i].size()
                 << " elementos\n";

            total += hash->table[i].size() - 1;
        }
    }

    cout << "Total de colisoes: "
         << total
         << endl;
}

// Mostra informações gerais
void hash_info(hash_t* hash) {

    cout << "\n===== INFORMACOES =====\n";

    cout << "Elementos: "
         << hash_size(hash)
         << endl;

    cout << "Fator de carga: "
         << hash_load_factor(hash)
         << endl;

    cout << "Vazia? ";

    if (hash_empty(hash))
        cout << "Sim\n";
    else
        cout << "Nao\n";
}

int main() {

    hash_t tabela;

    hash_insert(&tabela, 3);
    hash_insert(&tabela, 10);
    hash_insert(&tabela, -6);
    hash_insert(&tabela, 9);
    hash_insert(&tabela, 17);
    hash_insert(&tabela, 24);

    hash_show(&tabela);

    cout << "\nBusca 10: "
         << hash_search(&tabela, 10)
         << endl;

    cout << "Busca 99: "
         << hash_search(&tabela, 99)
         << endl;

    hash_delete(&tabela, 10);

    cout << "\nDepois da remocao:\n";

    hash_show(&tabela);

    hash_collisions(&tabela);

    hash_info(&tabela);

    hash_clear(&tabela);

    cout << "\nDepois do clear:\n";

    hash_show(&tabela);

    hash_info(&tabela);

    return 0;
}