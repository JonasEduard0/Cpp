#pragma once //evita incluir 2 vezes o msm .h.

#include "Produto.h"
#include "Nodo.h"
#include <cmath>

class ArvoreBinaria {   //com árvore balanceada, busca = O(log n).
    int quant;          //quantidade de nós na arvore.
    Nodo* root;         //aponta pra raiz.

    
    Nodo* localEntrada(Nodo* subArvore, const Produto& p);

    void removeZero(Nodo* sair);
    void removeUm(Nodo* sair);
    void removeNFilhos(Nodo* sair);

    Nodo* maiorDescendente(Nodo* no);

    Nodo* getP(Nodo* entrousaiu);
    Nodo* getQ(Nodo* p);
    int getFatorBalanceamento(Nodo* no);
    int getAltura(Nodo* no);

    void executaBalanceamento(Nodo* entrousaiu);
    void rotacaoUnica_EsqEsq(Nodo* P, Nodo* Q);
    void rotacaoUnica_DirDir(Nodo* P, Nodo* Q);
    void rotacaoDupla_EsqDir(Nodo* P, Nodo* Q);
    void rotacaoDupla_DirEsq(Nodo* P, Nodo* Q);


public: //em public, métodos q podem ser acessados pelo cliente.
    ArvoreBinaria() { quant = 0; };
    ArvoreBinaria(const ArvoreBinaria& outra) { this->quant = outra.quant; };

    void  setQuant(int quant) { this->quant = quant; };
    void  setRoot(Nodo* root) { this->root = root; };

    int   getQuant() { return quant; };
    Nodo* getRoot()const { return root; };

    void preOrdem(Nodo* no);
    void emOrdem(Nodo* no);
    void posOrdem(Nodo* no);

    void insert(Produto& p);

    void remove(const Produto& p);
    Nodo* buscar(Nodo* subArvore, const Produto& outro);
    Nodo* getAntecessor(Nodo* no);
};

void ArvoreBinaria::preOrdem(Nodo* no) { //Visita Esquerda Direita
    if (no != NULL) {
        cout << "(" << no->getItem().getId() << "," << no->getItem().getPreco() << "), ";
        preOrdem(no->getEsq());
        preOrdem(no->getDir());
    }
}

void ArvoreBinaria::emOrdem(Nodo* no) { //EVD
    if (no != NULL) {
        emOrdem(no->getEsq());
        cout << "(" << no->getItem().getId() << "," << no->getItem().getNome() << "), ";
        emOrdem(no->getDir());
    }
}

void ArvoreBinaria::posOrdem(Nodo* no) { //EDV
    if (no != NULL) {
        posOrdem(no->getEsq());
        posOrdem(no->getDir());
        cout << "(" << no->getItem().getId() << "," << no->getItem().getPreco() << "), ";
    }
}

Nodo* ArvoreBinaria::localEntrada(Nodo* no, const Produto& p) {//passa nó analisado atual(pai) e o p q qr entrar.
    if (p.getId() < no->getItem().getId()) {      //se o q qr entrar < o pai
        if (no->getEsq() != NULL)
            return localEntrada(no->getEsq(), p); //recomeça o processo passando o nó a esquerda e p.
    }
    else {
        if (no->getDir() != NULL)
            return localEntrada(no->getDir(), p); //senão,recomeça passando o nó a direita e p.
    }
    return no;  //retorna o pai
}

void ArvoreBinaria::insert(Produto& p) {
    if (root == NULL) {     //caso árvore esteja vazia.
        root = new Nodo(p); //cria um nó passando p que será a raiz.
        quant++;            //aumenta a quantidade de nós na árvore.
    }
    else {
        Nodo* pai = localEntrada(root, p); //senão,procura pai do produto a partir da raiz.

        if (p.getId() == pai->getItem().getId()) {//se id do q qr entrar == do pai:
            cout << "\nElemento ja existe\n";
            return;                               //já existe, então encerra aqui.
        }

        Nodo* novo = new Nodo(p); //se não encerrar acima
        novo->setPai(pai);        //cria um nó pro p e seta o pai.

        if (p.getId() < pai->getItem().getId()) {//se id do novo < id do pai
            pai->setEsq(novo);                   //o novo vai pra esquerda.
        } else{               //senão(id novo > id do pai)
            pai->setDir(novo); //vai pra direita do pai.
        }
        quant++; //+1 nó na árvore.
        executaBalanceamento(novo);
}}

void ArvoreBinaria::removeZero(Nodo* sair) { //nodo q vai sair,0 filhos.
    Nodo* pai = sair->getPai(); //pai = o endereço do pai do q vai sair.

    if (pai == NULL) {     //se nn tem pai, entao so tem raiz
        root = NULL;       //só anular a raiz.
    }
    else if (sair->getItem().getId() < pai->getItem().getId()) { //se id pai > id do sair
        pai->setEsq(NULL); //entao esse é o nó sair, zera a esquerda.
    } else{
        pai->setDir(NULL); //senão, está á direita, anula direita.
}}

void ArvoreBinaria::removeUm(Nodo* sair) { //nodo q vai sair, com 1 filho.
    Nodo* pai = sair->getPai();           //pega o pai do nó q vai sair.
    Nodo* filho = sair->getFilhounico();  //pega o filho do nó q vai sair.

    if (pai == NULL) { //o pai é o root e basta apontar pra o filho
        root = filho;  //root aponta pro filho do nó q vai sair, tornando-o a nova raiz.
    } else {
        filho->setPai(pai); //filho aponta pro pai do nó q vai sair(avô).

        if (filho->getItem().getId() > pai->getItem().getId()) { //se id do filho > q do pai:
            pai->setDir(filho); //pai aponta pro filho na direita.
        } else {
            pai->setEsq(filho);
}}}

Nodo* ArvoreBinaria::maiorDescendente(Nodo* no) { //pega o maior descendente do nó passado.
    if (no == NULL) {
        cout << "Esse no nao tem sucessor.";
        return NULL;
    }
    if (no->getDir() == NULL) {  //se nao tem filho na direita, é o maior.
        return no;
    }
    return maiorDescendente(no->getDir()); //se tem filho na dir, desce pra direita.
}

Nodo* ArvoreBinaria::getAntecessor(Nodo* no) {//pega antecessor do nó(maior entre menores,lado esq menor nivel a dir).
    if (no->getEsq() != NULL) {
        return maiorDescendente(no->getEsq()); //se tem filho na esq, pega o maior descendente dele.
    } else {
        return NULL;
}}

Nodo* ArvoreBinaria::buscar(Nodo* subArvore, const Produto& outro) {
    if (subArvore == NULL) { //se nó atual for NULL, não achou.
        return NULL;
    }
    Produto item = subArvore->getItem(); //pega o item do nó atual.
    if (outro.getId() == item.getId()) { //se id do produto procurado == id do nó atual:
        return subArvore;                //retorna o nó atual.
    } else if (outro.getId() < item.getId()) {       //se id do produto procurado < id do nó atual:
        return buscar(subArvore->getEsq(), outro); //desce pra esq e busca lá.
    } else { //se id do produto procurado > id do nó atual:
        return buscar(subArvore->getDir(), outro); //desce pra dir e busca lá.
}}

void ArvoreBinaria::remove(const Produto& p) {
    Nodo* sair = buscar(root, p); //procura o nó q tem o produto p, a partir da raiz.

    if (sair != NULL) { //se encontrou o nó:
        Nodo* pai = sair->getPai();              //GUARDA ANTES
        int numFilhos = sair->getNumeroFilhos(); //pega o número de filhos do nó q vai sair.

        if (numFilhos == 0) {                    //se não tem filhos:
            removeZero(sair);    //chama remoção de nó sem filhos.
        }
        else if (numFilhos == 1) { //se tem 1 filho:
            removeUm(sair);       //chama remoção de nó com 1 filho.
        }
        else {                   //se tem 2 filhos:
            removeNFilhos(sair); //chama remoção de nó com 2 filhos.
        }
        quant--; //decrementa a quantidade de nós.
        if (pai != NULL) {
            executaBalanceamento(pai);
}}}

void ArvoreBinaria::removeNFilhos(Nodo* sair) {
    Nodo* antecessor = getAntecessor(sair);
    sair->setItem(antecessor->getItem());

    if (antecessor->getNumeroFilhos() == 0) {
        removeZero(antecessor);  //remove o antecessor (q terá 0 ou 1 filho).
    } else {
        removeUm(antecessor);
}}

//Balanceamento AVL: Fator balanceamento = h(subarvore direita) - h(esq).
//Se o fator de balanceamento for >=2 ou <=-2, está desbalanceada.
//Cada nó pode ser balanceado, não só raiz.
//Chama o nó desbalanceado de P, Q a subarvore do inserido, e R o neto se caso 1.
//Pode fazer 1 ou 2 rotações, em ambas pode ficar um terceiro filho, então vê onde recoloca ele na arvore.
//Se inserido na esq depois dir ou vice-versa(-+ou+-), faz 2. R -> Q depois R -> P.
//Se inserido na esq depois esq ou dir dir(--ou++), faz 1 rotação. Q -> P.

int ArvoreBinaria::getAltura(Nodo* no) { //passa nó base onde começa calcular altura.
    if (no == NULL) { //se o nó for nulo, altura = 0.
        return 0;
    }
    int h_esq = getAltura(no->getEsq());
    int h_dir = getAltura(no->getDir());

    if (h_esq > h_dir) { 
        return h_esq + 1;
    } else{
        return h_dir + 1;
}}

int ArvoreBinaria::getFatorBalanceamento(Nodo* no) { //passa um no como partida pra calcular.
    if (no == NULL) return 0; //se for nulo, entao 0.
    return getAltura(no->getDir ()) - getAltura(no->getEsq()); //fator=h(esq)-h(dir).
}

Nodo* ArvoreBinaria::getP(Nodo* entrousaiu) { //Pega nó desbalanceado P a partir do nó que entrou/saiu.
    Nodo* pai = entrousaiu->getPai();         //Pega o pai do nó que entrou/saiu.
    while (pai != NULL) {                     //Enquanto não chegar na raiz, pois nn tem pai lá.
        int fator = getFatorBalanceamento(pai); //Pega o fator de balanceamento do pai atual.
        if (abs(fator) >= 2) {    //Se o fator for >=2 ou <=-2, é o nó desbalanceado P.
            return pai;           //Então retorna ele.
        }
        pai = pai->getPai();      //Sobe um nível na árvore, pro pai.
    }
    return NULL;
}

Nodo* ArvoreBinaria::getQ(Nodo* p) { //Q é filho mais perto do P em relação ao q entrou/saiu.
    Nodo* q; //cria um nó q.
    if (getFatorBalanceamento(p) > 0){ //se fator P >0, Q é a subárvore direita pois ++.
        q = p->getDir();
    } else{
        q = p->getEsq(); //se p < 0, então esquerda-.
    }
    getFatorBalanceamento(q); //atualiza o fator de Q.
    return q; //retorna o q encontrada em relação a p.
}

void ArvoreBinaria::rotacaoUnica_EsqEsq(Nodo* P, Nodo* Q) { //--
    Nodo* paiP = P->getPai(); //Guarda o pai de P, que vira pai de Q.
    Nodo* A = Q->getDir();    //Filho sobressalente a dir de Q, que vira a esq de P.

    Q->setDir(P); //Nó q desbalanceou vira direita de Q.
    P->setPai(Q); //Logo, pai de P é Q.
    P->setEsq(A); //O A deslocado vira esquerda de P.

    if (A != NULL) A->setPai(P); //P vira pai de A se ele não for nulo.

    Q->setPai(paiP);  //Atualiza o pai de Q, pois Q trocou com P.

    if (paiP == NULL) root = Q; //se P não tiver pai, raiz.
    else if (Q->getItem().getId() > paiP->getItem().getId()) { //Se Q > paiP, vai pra direita.
        paiP->setDir(Q);
    } else paiP->setEsq(Q);
}

void ArvoreBinaria::rotacaoUnica_DirDir(Nodo* P, Nodo* Q) { //=, só troca esq->dir.
    Nodo* paiP = P->getPai();
    Nodo* A = Q->getEsq();

    Q->setEsq(P);
    P->setPai(Q);
    P->setDir(A);

    if (A != NULL) A->setPai(P);

    Q->setPai(paiP);

    if (paiP == NULL) root = Q;
    else if (Q->getItem().getId() > paiP->getItem().getId()) paiP->setEsq(Q);
    else paiP->setDir(Q);
}

void ArvoreBinaria::rotacaoDupla_DirEsq(Nodo* P, Nodo* Q) {
    Nodo* R = Q->getEsq(); // R é o "neto" de P. Como o caso é Dir-Esq(+-), R fica à esquerda de Q.

//Rotação simples Esq-Esq em Q. R sobe e Q desce para a direita. Corrige o desbalanceamento entre Q e R.
    rotacaoUnica_EsqEsq(Q, R);

//SEGUNDA ROTAÇÃO: Rotação simples Dir-Dir em P. R sobe novamente e P desce para a esquerda.
//Corrige o desbalanceamento entre P e R.
    rotacaoUnica_DirDir(P, R);
}

void ArvoreBinaria::rotacaoDupla_EsqDir(Nodo* P, Nodo* Q) { //=, só troca esq->dir.
    Nodo* R = Q->getDir();
    rotacaoUnica_DirDir(Q, R);
    rotacaoUnica_EsqEsq(P, R);
}

void ArvoreBinaria::executaBalanceamento(Nodo* entrousaiu) { //nó q entou ou saiu e desbalanceou.
    Nodo* p = getP(entrousaiu); //Pega nó desbalanceado em relação ao no q entrou/saiu.

    if (p != NULL) {        //Tem alguem desbalanceado, senao volta nulo.
        Nodo* q = getQ(p);  //Pega Q tendo sabendo quem é P.

        if (getFatorBalanceamento(p) > 0 && getFatorBalanceamento(q) >= 0) { //se caso ++
            rotacaoUnica_DirDir(p, q);  //1 rotacao á direita.
        }
        else if (getFatorBalanceamento(p) < 0 && getFatorBalanceamento(q) <= 0) { //se caso --
            rotacaoUnica_EsqEsq(p, q);  //1 rotacao á esquerda.
        }
        else if (getFatorBalanceamento(p) > 0 && getFatorBalanceamento(q) < 0) {// se caso -+
            rotacaoDupla_EsqDir(p, q);  //2 rotações.
        }
        else {                                    //se caso +-
            rotacaoDupla_DirEsq(p, q);  //2 rotações.
}}}