#pragma once

class ListaContigua {
    int tam, quant; //L.C.deve ter tamanho e quantidade de elementos dentro.
    Livros* lista;  //Cria um vetor dinâmico com o nome da classe do objeto a ser inserido.
public:
    ListaContigua();
    ~ListaContigua();

    ListaContigua(int tam); //Construtor de sobrecarga(2º construtor), apenas para inserir o tam na lista.

    void shiftEnd(int index); //Aumenta + 1 a posicao dos elementos a partir do index(posicao q quer pôr o elemento).
    void insert(Livros l, int index); //Insere o objeto 'l' e atributos na posicao 'index'.

    void shiftFront(int index);//Sobrescreve o index com o próximo elemento, e diminui a posicao dos proximos - 1.
    void remove(int index);    //Remove o elemento do index, mas fica lixo.

    void imprime();

    int buscaBinaria(int cpfProcurado); //Em lista ordenada do menor para o maior, divide pela metade e procura.
    int bubbleSort(int cpfProcurado);   //Tipo de ordenação, percorre a lista comparando elementos e trocando se estiverem na ordem errada.

    int proximocirc(int n);
    int anteriorcirc(int n);
};

ListaContigua::ListaContigua() {
    tam = 0;
    quant = 0;
}

ListaContigua::ListaContigua(int tam) {
    this->tam = tam; | Recebe o valor de tam do outro construtor.
    this->quant = 0;
    this->lista = new Livros[tam]; // Cria uma lista com tamanho tam já definido do outro construtor.
} 

void ListaContigua::insert(Pessoa l, int index) { // Objeto 'l' inserido na posicao 'index'.
    if (quant < tam) {           // Ou seja, se ainda tiver espaco na lista...
        shiftEnd(index);         // Aumenta + 1 a posição a partir do index.
        lista[index].copia(l);   // Copia 'l' e põe no index.
        quant++;                 // Aumenta um elemento na lista.
    } else cout << "Lista cheia";// Se já estiver cheia.
}

void ListaContigua::shiftEnd(int index) { //Percorre do final da lista ao index aumentando + 1 a posicao do elemento analisado .
    for (int i = quant; i >= index; i--) { //Quando i = index, aumenta a posição de todos, até lá, como está na posição máxima, diminui - 1 até o index.
        lista[i].copia(lista[i - 1]);      //Copia o que está atrás e é levado a frente.
    }
} 

void ListaContigua::shiftFront(int index) {
    for (int i = index; i < quant - 1; i++) { //Procura o index a partir do início da lista.
        lista[i] = lista[i + 1]; //A partir de index, sobrescreve o elemento atual pelo próximo.
}} 

void ListaContigua::remove(int index) { //Remove o elemento do index, deixando vazio.
    if (quant > 0) {
        shiftFront(index); //Executa shiftFrot para diminuir a posição do próximo elemento, tirando o buraco no meio.
        quant--;           //Diminui a quantidade de elementos.
    } else cout << "Lista vazia"; //Se lista vazia.
} 

void ListaContigua::imprime() {
    for (int i = 0; i < quant - 1; i++) { //Para cada elemento da lista,
        lista[i].imprimir(); //usa o metodo imprimir da classe Pessoa para imprimir cada um.
}} 

int ListaContigua::bubbleSort(int cpfProcurado) {
    int indexFinal = quant - 1;

    while (indexFinal > 0) {
    for (int i = 0; i <= indexFinal - 1; i++) {
        if (lista[i].getCpf() > lista[i + 1].getCpf()) {
            Pessoa temp = lista[i]; //temp permite a troca dos valores.
            lista[i] = lista[i + 1];
            lista[i + 1] = temp;
        }
    }
    indexFinal--;
}}

int ListaContigua::busca(int cpfProcurado) {
    for (int i = 0; i <= quant - 1; i++) {
        if (lista[i].getCpf() == cpfProcurado) {
            return i;
        }
    }
    return -1;
}

int ListaContigua::buscaBinaria(int cpfProcurado) {
    int inicio = 0;
    int fim = tam - 1;
    int meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (lista[meio].getCpf() == cpfProcurado) return meio;
        else if (cpfProcurado < lista[meio].getCpf()) fim = meio - 1;
        else inicio = meio + 1;
    }
    return -1;
}

int ListaContigua::proximocirc(int n) {
    if (n >= 0 && n <= tam - 1) {//Nao teria sucessor se fosse contigua comum, return-1.
        if (n == tam - 1) return 0;
        else return n + 1;
}}

int ListaContigua::anteriorcirc(int n) {
    if (n >= 0 && n <= tam - 1) {
        if (n = 0) return tam - 1;
        else return n - 1;
}}}