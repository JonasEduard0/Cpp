#pragma once

class NodoDuplo { //Nó duplo, para duplamente encadeada, tem: |endereço do anterior| , item, endereço do proximo.
    Pessoa item;
    NodoDuplo* prox;
    NodoDuplo* ant;  //Agora, aponta tambem pro anterior.

public:
    NodoDuplo();
    NodoDuplo(const Pessoa& p);
    ~NodoDuplo() {};

    void setItemD(Pessoa& p)      { this->item = p; };
    void setAnt(NodoDuplo* ant)   { this->ant = ant; };  // Define o endereço do anterior.
    void setProxD(NodoDuplo* prox){ this->prox = prox; };

    Pessoa getItemD()    { return item; };
    NodoDuplo* getAnt()  { return ant; }; // Retorna o nodo anterior.
    NodoDuplo* getProxD(){ return prox; };
};

NodoDuplo::NodoDuplo() {
    prox = NULL;
    ant = NULL;
}

NodoDuplo::NodoDuplo(const Pessoa & p) {
    prox = NULL;
    ant = NULL;
    item = p;
}