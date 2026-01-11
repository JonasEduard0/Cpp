#include "Nodo.h"

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
        } else {
            return dir;
        }
    }
    return NULL; //retorna vazio se condicoes nao atendidas.
}