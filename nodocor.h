#pragma once

#include "Produto.h"

enum Cor { VERMELHO, PRETO };

class Nodo {
    Produto item;
    Cor cor;
    Nodo* pai;
    Nodo* esq;
    Nodo* dir;
public:
    Nodo(const Produto& p) {
        item = p;
        cor = VERMELHO;
        pai = esq = dir = NULL;
    }

    Produto getItem(){ return item; }
    Cor getCor()  { return cor; }
    Nodo* getPai(){ return pai; }
    Nodo* getEsq(){ return esq; }
    Nodo* getDir(){ return dir; }

    void setItem(const Produto& p) { item = p; }
    void setCor(Cor c) { cor = c; }
    void setPai(Nodo* p) { pai = p; }
    void setEsq(Nodo* e) { esq = e; }
    void setDir(Nodo* d) { dir = d; }
};