#pragma once

class Encadeada { // Estrutura q gerencia os nós.
    int quant;    // Quantidade de elementos / espaços da lista.
    Nodo* head;   // Ponteiro head aponta pro primeiro nó.
public:
    Encadeada();
    ~Encadeada() {};

    void insertE(Pessoa& p); // Insere um novo nó p no início.
    void removeE();          // Remove o primeiro nó.

    void insertpos(int n, Pessoa & p); // Inserir em uma posição específica.
    void removepos(int n);             // Remover uma posicao especifica.

    Nodo * getElemento(int n);         // Pega endereço do elemento desejado, é a busca da lista encadeada.

    Nodo* proximoE(int n);
    Nodo* anteriorE(int n);
};

Encadeada::Encadeada() {
    quant = 0;
    head = NULL; // Zera os atributos pois ainda nenhum nó.
}

void Encadeada::insertE(Pessoa& p) 
    Nodo* novo = new Nodo(); // Cria novo nó.
    novo->setItem(p);    // Insere p no novo no.
    novo->setProx(head); // O novo nó passa a apontar para o antigo primeiro
    head = novo;         // head agora aponta pro primeiro e novo nó da lista.
    quant++;
}

void Encadeada::removeE() {
    head = head->getProx(); // Pra remover da lista, basta ninguém apontar pra ele, o 2º nó vira 1º.
    quant--;
}

void Encadeada::insertpos(int n, Pessoa& p) {
    Nodo* novo = new Nodo();
    novo->setItem(p);

    Nodo* anterior = this->getElemento(n - 1); // Pega a posiçao do nodo anterior.
    novo->setProx(anterior->getProx()); // O novo no pega o endereço / posicao do proximo.
    anterior->setProx(novo);            // O nodo anterior agora tem o endereço do novo.

    quant++;
}

void Encadeada::removepos(int n) {
    Nodo* anterior = this->getElemento(n - 1); // Define e pega o nodo anterior do excluido.
        Nodo* excluido = anterior->getProx();  // Pega o endereço do excluido do prox do anterior.
        anterior->setProx(excluido->getProx());// Agora o anterior guarda o endereço do da frente do excluido.
        quant--;
}

Nodo* Encadeada::getElemento(int n) { //Retorna endereço do elemento buscado n.
    Nodo* p = head; // Cria um apontador pro head(q aponta pro 1º).
    int i = 1;      // Conta quntas vezes andou até elemento.

    while (i <= n - 1 && p->getProx() != NULL) { //1 até o anterior do buscado, pois ele q tem o endereço.
        p = p->getProx(); | Copia endereço do proximo.
        i++;
    } 

    if (i == n) { //Quanto elemento buscado = contador
        return p; //retorna endereço.
    } else return NULL;
}

Nodo* Encadeada::proximoE(int n) {
    if (n <= quant - 1) {
        Nodo* proximo = this->getElemento(n + 1);
        return proximo;
    }
    else return head;
}

Nodo* Encadeada::anteriorE(int n) {
    if (n >= 2) {
        Nodo* anterior = this->getElemento(n - 1);
        return anterior;
    }
    else {
        Nodo* ultimo = this->getElemento(quant);
        return ultimo;
    }
}