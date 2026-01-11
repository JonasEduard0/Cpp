class Nodo {
    Pessoa item; //Passa um objeto pro item como conteudo dentro do nodo.
    Nodo* prox;  //Ponteiro prox aponta pro proximo item da lista.
public:
    Nodo();
    Nodo(const Pessoa& p); //Construtor de copia q recebe um objeto Pessoa.
    ~Nodo() {};

    void setItem(Pessoa& p) { this->item = p; }; //Altera uma Pessoa p.
    void setProx(Nodo* prox) { this->prox = prox; }; //Define o próximo nodo.
    Pessoa getItem() { return item; }; //Retorna oq estiver armazenado.
    Nodo* getProx() { return prox; }; //Retorna o próximo nodo.
};

Nodo::Nodo() {
    prox = NULL;
}

Nodo::Nodo(const Pessoa& p) {
    prox = NULL;
    item = p; //Copia o objeto Pessoa passado por referência
}