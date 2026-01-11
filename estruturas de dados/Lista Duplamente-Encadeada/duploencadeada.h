#pragma once

class DuploEncadeada {
    int quant;
    NodoDuplo* head;
public:
    DuploEncadeada();
    ~DuploEncadeada() {};

    void insertD(Pessoa& p);
    void removeD();

    void insertposD(int n, Pessoa& p);
    void removeposD(int n);

    NodoDuplo* getElementoD(int n);

    NodoDuplo* proximocircD(int n);
    NodoDuplo* anteriorcircD(int n);
};

DuploEncadeada::DuploEncadeada() {
    quant = 0;
    head = NULL;
}

void DuploEncadeada::insertD(Pessoa& p) {
    NodoDuplo* novo = new NodoDuplo();
    novo->setItemD(p);
    novo->setProxD(head);
    novo->setAnt(NULL);  //Como insere na 1 pos, o ant aponta pro nada.

    if (quant > 0) { //Agora, se tiver um nodo,      
        head->setAnt(novo);
    }
    head = novo;
    quant++;
}

void DuploEncadeada::removeD() {
    head = head->getProxD();//head aponta pro próximo do primeiro, q é o endereço do segundo.
    head->setAnt(NULL);     //Agora o primeiro da lista q era o segundo aponta pra nada.
    quant--;                //Ninguém aponta pro antigo primeiro, entao não existe.
}

void DuploEncadeada::insertposD(int pos, Pessoa& p) {
    NodoDuplo* novo = new NodoDuplo();
    novo->setItemD(p);

    NodoDuplo* n = this->getElementoD(pos);
    NodoDuplo* anterior = this->getElementoD(pos - 1);

    novo->setProxD(n);
    novo->setAnt(anterior);
    anterior->setProxD(novo);
    n->setAnt(novo);

    quant++;
}

void DuploEncadeada::removeposD(int n) {
    NodoDuplo* anterior = this->getElementoD(n - 1);
    NodoDuplo* frente = this->getElementoD(n + 1);

    anterior->setProxD(frente);
    frente->setAnt(anterior);

    quant--;
}

NodoDuplo* DuploEncadeada::getElementoD(int n) {
    NodoDuplo* p = head;
    int i = 1;

    while (i <= n - 1 && p->getProxD() != NULL) {
        p = p->getProxD();
        i++;
    } 
    if (i == n) return p;
    else return NULL;
}

NodoDuplo* DuploEncadeada::proximocircD(int n) {
    NodoDuplo* elemento = getElementoD(n);
    return elemento->getProxD();
}

NodoDuplo* DuploEncadeada::anteriorcircD(int n) {
    NodoDuplo* elemento = this->getElementoD(n);
    return elemento->getAnt();
}