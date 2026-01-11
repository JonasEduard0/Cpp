/*
Se 2+ chaves produzirem o mesmo hash code, é uma colisão. Neste caso o Hash armazena esses pares no mesmo bucket como uma lista encadeada ou outra.
M = mod(modulo), resto de uma divisao. Deve ser o tamanho da lista pra caber na tabela. Prefira primos.
Nem sempre “mais contas” significam menos colisões. É preciso testar e medir.
Não existe função perfeita. O melhor depende dos seus dados. O importante é experimentar, contar colisões e comparar.

 Divisão
Método mais simples. Pegamos a chave e fazemos o resto da divisão pelo tamanho da tabela:
h(k) = k mod M.

 Hash para string
Transformar letra em numero (A=1, B=2, …) e somar. Esse somatório é então reduzido pelo tamanho da tabela (mod M).
Podemos criar variações: multiplicar cada letra por um fator, acumular com base (hash = (hash*37 + letra) mod M).

 Meio do quadrado
Embaralhar mais os dígitos da chave. O processo é:
1. Eleva k ao quadrado; 2. Pegar os dígitos centrais do resultado; 3. Aplicar mod M.
Exemplo: k = 3121 → k² = 9740641. Pegamos o miolo 406 → 406 mod 10 = 6. Portanto, a chave 3121 vai para a posição 6. Pode misturar os dígitos e pra espalhar melhor.

 Extração
Neste método, em vez de usar a chave inteira, escolhemos apenas uma parte dela.
Exemplo: uma matrícula universitária 2014.22.123. os primeiros dígitos sao o ano e, mas os 3 últimos diferenciam os alunos. Podemos então usar 123 mod M para decidir a posição.

 Dobramento
Cortar chave em blocos de mesmo tamanho, somá-los e aplicar M.
Exemplo: 13320020 → quebramos em blocos 133, 200 e 20. Somamos: 133 + 200 + 20 = 353. Depois aplicamos 353 mod 10 = 3. A chave vai para a posição 3.
Variação: no dobramento em sanfona, invertemos alguns blocos antes de somar, para misturar mais os dígitos.
Prós: aproveita todos os dígitos da chave. Cuidados: precisa escolher blocos de tamanho equilibrado.

 
  Tratamento de colisões
 Endereçamento fechado
Cada bucket guarda uma lista encadeada com as chaves daquele índice.
Prós: simples; sem “estouro” por bucket(limite é a memória). 
Contras: se o hash espalha mal, algumas listas ficam grandes.

 Endereçamento aberto/linear
Usamos apenas o vetor; em colisão, procuramos a próxima posição livre (busca linear circular), tem 3 repositorios por posiçao.
Prós: estrutura contígua (bom de cache), sem alocação de nós.
Contras: pode gerar clusters (aglomerados) e exigir rehash com mais frequência.
*/

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

const int M = 11;      // tamanho da tabela (preferencialmente primo)
const int VAZIO = -1;  // sentinela para array

   //MÉTODOS DE HASH

// Divisão
int hashDivisao(int k) {
    if (k < 0) k = -k;
    return k % M;
}

// Meio Quadrado
int hashMeioQuadrado(int k) {
    if (k < 0) k = -k;
    long long q = (long long)k * k;
    int meio = (q / 10) % 100;   // pega dígitos centrais
    return meio % M;
}

// Extração (últimos dígitos)
int hashExtracao(int k) {
    if (k < 0) k = -k;
    int extraido = k % 100;
    return extraido % M;
}

// Dobramento
int hashDobramento(int k) {
    if (k < 0) k = -k;
    int soma = 0;
    while (k > 0) {
        soma += k % 100;
        k /= 100;
    }
    return soma % M;
}

// Sanfona
int hashSanfona(int k) {
    if (k < 0) k = -k;
    int res = 0;
    bool soma = true;

    while (k > 0) {
        int bloco = k % 100;
        if (soma) res += bloco;
        else res -= bloco;
        soma = !soma;
        k /= 100;
    }

    if (res < 0) res = -res;
    return res % M;
}


   //TRATAMENTO DE COLISÃO — LISTA ENCADEADA

struct No {
    int valor;
    No* prox;
};

void inserirLista(No* tabela[], int k) {
    int idx = hashDivisao(k);  // pode trocar o método aqui
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = k;
    novo->prox = tabela[idx];
    tabela[idx] = novo;
}

No* buscarLista(No* tabela[], int k) {
    int idx = hashDivisao(k);
    No* p = tabela[idx];
    while (p != NULL) {
        if (p->valor == k) return p;
        p = p->prox;
    }
    return NULL;
}

void imprimirLista(No* tabela[]) {
    for (int i = 0; i < M; i++) {
        cout << "[" << i << "] ";
        No* p = tabela[i];
        while (p != NULL) {
            cout << p->valor << " -> ";
            p = p->prox;
        }
        cout << "•\n";
    }
}

   //TRATAMENTO DE COLISÃO — ARRAY (SONDAGEM LINEAR)

void inserirArray(int t[], int k) {
    int idx = hashDivisao(k);
    int passos = 0;

    while (t[idx] != VAZIO && passos < M) {
        idx = (idx + 1) % M;
        passos++;
    }

    if (passos == M) {
        cout << "Tabela cheia!\n";
        return;
    }

    t[idx] = k;
}

int buscarArray(int t[], int k) {
    int idx = hashDivisao(k);
    int passos = 0;

    while (t[idx] != VAZIO && passos < M) {
        if (t[idx] == k) return idx;
        idx = (idx + 1) % M;
        passos++;
    }

    return -1;
}

void imprimirArray(int t[]) {
    for (int i = 0; i < M; i++) {
        if (t[i] == VAZIO) cout << "[" << i << "] •\n";
        else cout << "[" << i << "] " << t[i] << "\n";
    }
}

int main() {

    /* ---------- LISTA ENCADEADA ---------- */
    No* tabelaLista[M];
    for (int i = 0; i < M; i++) tabelaLista[i] = NULL;

    inserirLista(tabelaLista, 37);
    inserirLista(tabelaLista, 48);
    inserirLista(tabelaLista, 59);
    inserirLista(tabelaLista, 70);

    cout << "\nTabela com Lista Encadeada:\n";
    imprimirLista(tabelaLista);

    if (buscarLista(tabelaLista, 48))
        cout << "48 encontrado (lista)\n";
    else
        cout << "48 nao encontrado (lista)\n";

    /* ---------- ARRAY ---------- */
    int tabelaArray[M];
    for (int i = 0; i < M; i++) tabelaArray[i] = VAZIO;

    inserirArray(tabelaArray, 37);
    inserirArray(tabelaArray, 48);
    inserirArray(tabelaArray, 59);
    inserirArray(tabelaArray, 70);

    cout << "\nTabela com Array (Sondagem Linear):\n";
    imprimirArray(tabelaArray);

    int pos = buscarArray(tabelaArray, 59);
    if (pos != -1)
        cout << "59 encontrado na posicao " << pos << " (array)\n";
    else
        cout << "59 nao encontrado (array)\n";

    return 0;
}