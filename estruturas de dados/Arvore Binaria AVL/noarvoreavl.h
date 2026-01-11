#pragma once

#include "Produto.h" //Passa o conteudo do nó.

class Nodo { //cada nó é um elemento da arvore, tem: *pai(q esta acima),Item,*esq e *dir.
private:
    Produto item; //classe-conteudo do nó, nesse caso um produto.
    Nodo* pai;    //q está acima desse nó. há o termo tio(lado do pai) e avô(pai do pai) tmb.
    Nodo* esq;    //subarvore(galho) esquerda, q está abaixo.
    Nodo* dir;    //subarvore(galho) direita.
public:
    Nodo();
    Nodo(const Produto& p);
    Nodo(const Nodo& orig);

    void setItem(const Produto& item) { this->item = item; };
    void setPai(Nodo* pai) { this->pai = pai; };
    void setEsq(Nodo* esq) { this->esq = esq; };
    void setDir(Nodo* dir) { this->dir = dir; };

    Produto getItem() const { return item; }; //esses const pode ignorar em provas.
    Nodo* getPai() const { return pai; };
    Nodo* getEsq() const { return esq; };
    Nodo* getDir() const { return dir; };

    int getNumeroFilhos() const;
    Nodo* getFilhounico() const;
};

Nodo::Nodo() {
    pai = NULL;
    esq = NULL;
    dir = NULL;
}

Nodo::Nodo(const Nodo& orig) {
    item = orig.item;
    pai = NULL;
    esq = NULL;
    dir = NULL;
}

Nodo::Nodo(const Produto& p) {
    item = p;
    pai = NULL;
    esq = NULL;
    dir = NULL;
}

int Nodo::getNumeroFilhos() const { //retorna quantos filhos o nó tem (0,1 ou 2).
    int c = 0;
    if (esq != NULL) { //se tem na esq, c aumenta 1.
        c++;
    }
    if (dir != NULL) { //se tem na dir, c aumenta.
        c++;
    }
    return c; //se nenhum filho retorna o valor inicial(0).
}

Nodo* Nodo::getFilhounico() const {
    if (getNumeroFilhos() == 1) { //se tiver um filho
        if (esq != NULL) {
            return esq; //retorna esq se la nn estiver nulo.
        }
        else {
            return dir;
        }
    }
    return NULL; //retorna vazio se condicoes nao atendidas.
}