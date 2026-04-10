#include <iostream>
using namespace std;

//Função que ordena o vetor usando Insertion Sort duplo.
void insertionSortDuplo(int vetor[], int n) { //Recebe vetor de ints, e tamanho. Retorna nada
    int i = 0; //variável de controle do laço principal (anda de 2 em 2).

    // Laço principal: percorre todo vetor
    while (i < n) { //Enquanto não chegar ao fim do vetor.

        // Caso especial: sobrou apenas 1 elemento (vetor de tam ímpar). Não dá pra pegar 2.
        if (i == n - 1) {
            int chave = vetor[i]; // Guarda o valor a ser inserido
            int j = i - 1; // Começa a comparar com o elemento anterior

            // desloca elementos maiores para a direita
            while (j >= 0 && vetor[j] > chave){ //Enquanto ñ saiu do vetor e atual é maior q chave
                vetor[j + 1] = vetor[j]; // Move elemento para a direita
                j--; // vai para o elemento anterior
            }

            vetor[j + 1] = chave; // coloca o elemento na posição correta
            break; // termina o if especial
        }

        // Pega dois elementos do vetor
        int a = vetor[i]; // Pega primeiro elemento
        int b = vetor[i + 1]; // Segundo elemento

        int menor, maior; // variáveis para guardar os valores ordenados

        // compara os dois elementos para saber qual é menor
        if (a < b) {
            menor = a; // a é o menor
            maior = b; // b é o maior
        } else {
            menor = b; // b é o menor
            maior = a; // a é o maior
        }

        // INSERÇÃO DO MENOR
        int j = i - 1; // começa do final da parte ordenada

        // Desloca elementos maiores que o menor
        while (j >= 0 && vetor[j] > menor) {
            vetor[j + 1] = vetor[j]; // Move elemento para a direita
            j--;                     // Continua andando para trás
        }

        vetor[j + 1] = menor; // coloca o menor na posição correta

        // INSERÇÃO DO MAIOR

        j = i; // começa do novo final da parte ordenada

        // desloca elementos maiores que o maior
        while (j >= 0 && vetor[j] > maior) {
            vetor[j + 1] = vetor[j]; // move elemento para a direita
            j--; // continua andando para trás, esquerda
        }

        vetor[j + 1] = maior; // coloca o maior na posição correta

        i += 2; // avança duas posições (pois já tratou dois elementos)
    }
}

void imprimir(int vetor[], int n) {
    for (int i = 0; i < n; i++) { // Percorre o vetor
        cout << vetor[i] << " ";  // Imprime cada elemento
    }
    cout << endl;
}

int main() {
    int vetor[] = {8, 3, 5, 2, 9, 1, 4}; // Vetor de exemplo

    int n = sizeof(vetor) / sizeof(vetor[0]); // calcula tamanho do vetor

    insertionSortDuplo(vetor, n); // chama a função de ordenação

    imprimir(vetor, n); // imprime o vetor ordenado

    return 0; // indica que o programa terminou corretamente
}