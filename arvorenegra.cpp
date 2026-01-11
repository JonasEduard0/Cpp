#pragma once

#include "NodoCor.h"

/*Red-black tree: quando há desbalanceamento, tem q ver a posição e cor do TIO do elemento q desbalanceou pra decidir qual correção usar.
1ª Todo nó é vermelho ou preto, 2ª raiz é preta, 3ª Todo nó nulo(Nil/null) é preta, 4ª nó vermelho, filhos só pretos, 5ª Pra cada nó, todos caminhos do nó pra folhas descendentes tem o mesmo número de nós PRETOS.*/

class RBTree {
private:
    Nodo* raiz; // raiz da árvore
    Nodo* nil;  // nó sentinela (representa NULL, sempre preto)

    // === ROTAÇÕES ===
    void rotacaoEsquerda(Nodo* x);
    void rotacaoDireita(Nodo* y);

    // === AJUSTES ===
    void fixInsert(Nodo* z); // corrige violações após inserção
    void fixRemove(Nodo* x); // corrige violações após remoção

    // === AUXILIARES ===
    void transplant(Nodo* u, Nodo* v); // troca subárvores
    Nodo* minimo(Nodo* x);             // menor nó de uma subárvore

public:
    RBTree();                      // construtor
    void insert(const Produto& p); // inserir produto
    void remove(int id);           // remover por id
    Nodo* buscar(int id);          // buscar por id
};

RBTree::RBTree() {
    // cria o nó sentinela
    nil = new Nodo(Produto());
    nil->setCor(PRETO);
    nil->setPai(nil);
    nil->setEsq(nil);
    nil->setDir(nil);

    // árvore começa vazia
    raiz = nil;
}

void RBTree::rotacaoEsquerda(Nodo* x) {
    // y será o filho direito de x
    Nodo* y = x->getDir();

    // subárvore esquerda de y vira subárvore direita de x
    x->setDir(y->getEsq());
    if (y->getEsq() != nil)
        y->getEsq()->setPai(x);

    // liga y ao pai de x
    y->setPai(x->getPai());

    if (x->getPai() == nil) raiz = y;
    else if (x == x->getPai()->getEsq()) x->getPai()->setEsq(y);
    else x->getPai()->setDir(y);

    // x vira filho esquerdo de y
    y->setEsq(x);
    x->setPai(y);
}

void RBTree::rotacaoDireita(Nodo* y) {
    Nodo* x = y->getEsq();

    y->setEsq(x->getDir());
    if (x->getDir() != nil)
        x->getDir()->setPai(y);

    x->setPai(y->getPai());

    if (y->getPai() == nil) raiz = x;
    else if (y == y->getPai()->getDir()) y->getPai()->setDir(x);
    else y->getPai()->setEsq(x);

    x->setDir(y);
    y->setPai(x);
}

void RBTree::insert(const Produto& p) {
    // cria novo nó (sempre vermelho)
    Nodo* z = new Nodo(p);
    z->setEsq(nil);
    z->setDir(nil);

    Nodo* y = nil;
    Nodo* x = raiz;

    // busca posição correta como numa BST normal
    while (x != nil) {
        y = x;
        if (p.getId() < x->getItem().getId())
            x = x->getEsq();
        else
            x = x->getDir();
    }

    z->setPai(y);

    if (y == nil)
        raiz = z;
    else if (p.getId() < y->getItem().getId())
        y->setEsq(z);
    else
        y->setDir(z);

    // corrige propriedades da Red-Black Tree
    fixInsert(z);
}

void RBTree::fixInsert(Nodo* z) {
    // enquanto o pai for vermelho, há violação
    while (z->getPai()->getCor() == VERMELHO) {

        // pai é filho esquerdo do avô
        if (z->getPai() == z->getPai()->getPai()->getEsq()) {
            Nodo* y = z->getPai()->getPai()->getDir(); // tio

            // CASO 1: tio vermelho
            if (y->getCor() == VERMELHO) {
                z->getPai()->setCor(PRETO);
                y->setCor(PRETO);
                z->getPai()->getPai()->setCor(VERMELHO);
                z = z->getPai()->getPai();
            }
            else {
                // CASO 2: z é filho direito
                if (z == z->getPai()->getDir()) {
                    z = z->getPai();
                    rotacaoEsquerda(z);
                }
                // CASO 3
                z->getPai()->setCor(PRETO);
                z->getPai()->getPai()->setCor(VERMELHO);
                rotacaoDireita(z->getPai()->getPai());
            }
        }
        else {
            // casos espelhados
            Nodo* y = z->getPai()->getPai()->getEsq();

            if (y->getCor() == VERMELHO) {
                z->getPai()->setCor(PRETO);
                y->setCor(PRETO);
                z->getPai()->getPai()->setCor(VERMELHO);
                z = z->getPai()->getPai();
            }
            else {
                if (z == z->getPai()->getEsq()) {
                    z = z->getPai();
                    rotacaoDireita(z);
                }
                z->getPai()->setCor(PRETO);
                z->getPai()->getPai()->setCor(VERMELHO);
                rotacaoEsquerda(z->getPai()->getPai());
            }
        }
    }
    // regra: raiz sempre preta
    raiz->setCor(PRETO);
}

Nodo* RBTree::buscar(int id) {
    Nodo* atual = raiz;

    while (atual != nil) {
        if (id == atual->getItem().getId())
            return atual;
        if (id < atual->getItem().getId())
            atual = atual->getEsq();
        else
            atual = atual->getDir();
    }
    return nil;
}

void RBTree::transplant(Nodo* u, Nodo* v) {
    if (u->getPai() == nil)
        raiz = v;
    else if (u == u->getPai()->getEsq())
        u->getPai()->setEsq(v);
    else
        u->getPai()->setDir(v);

    v->setPai(u->getPai());
}

Nodo* RBTree::minimo(Nodo* x) {
    while (x->getEsq() != nil)
        x = x->getEsq();
    return x;
}

void RBTree::remove(int id) {
    Nodo* z = buscar(id);
    if (z == nil) return;

    Nodo* y = z;
    Cor corOriginal = y->getCor();
    Nodo* x;

    if (z->getEsq() == nil) {
        x = z->getDir();
        transplant(z, z->getDir());
    }
    else if (z->getDir() == nil) {
        x = z->getEsq();
        transplant(z, z->getEsq());
    }
    else {
        y = minimo(z->getDir());
        corOriginal = y->getCor();
        x = y->getDir();

        if (y->getPai() == z)
            x->setPai(y);
        else {
            transplant(y, y->getDir());
            y->setDir(z->getDir());
            y->getDir()->setPai(y);
        }

        transplant(z, y);
        y->setEsq(z->getEsq());
        y->getEsq()->setPai(y);
        y->setCor(z->getCor());
    }

    if (corOriginal == PRETO)
        fixRemove(x);
}

void RBTree::fixRemove(Nodo* x) {
    while (x != raiz && x->getCor() == PRETO) {
        if (x == x->getPai()->getEsq()) {
            Nodo* w = x->getPai()->getDir();

            if (w->getCor() == VERMELHO) {
                w->setCor(PRETO);
                x->getPai()->setCor(VERMELHO);
                rotacaoEsquerda(x->getPai());
                w = x->getPai()->getDir();
            }

            if (w->getEsq()->getCor() == PRETO &&
                w->getDir()->getCor() == PRETO) {
                w->setCor(VERMELHO);
                x = x->getPai();
            }
            else {
                if (w->getDir()->getCor() == PRETO) {
                    w->getEsq()->setCor(PRETO);
                    w->setCor(VERMELHO);
                    rotacaoDireita(w);
                    w = x->getPai()->getDir();
                }

                w->setCor(x->getPai()->getCor());
                x->getPai()->setCor(PRETO);
                w->getDir()->setCor(PRETO);
                rotacaoEsquerda(x->getPai());
                x = raiz;
            }
        }
        else {
            x = raiz;
        }
    }
    x->setCor(PRETO);
}