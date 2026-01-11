#pragma once

class Pessoa { //Declara a classe no.h
private:         //Por padrão, já é private. Diz que só pode ser acessado no código da classe.
    int idade;   //Atributos.
    string nome;
    char sexo;

public: // Permite o código ser usado fora da classe.
    Pessoa();  // Construtor: nome = classe, inicializa variáveis.
    ~Pessoa(); // Destrutor.

    Pessoa(const Pessoa & outra); //Construtor de cópia, usado pra criar um novo objeto a partir de outro, chamado automaticamente.
    void copiar(const Pessoa& outro); // Método comum, usado pra copiar dados para um objeto já existente, chamado manualmente.
    void copia(Pessoa outra); // Necessário para a ListaContigua desta classe.

    void imprimir();  // Imprime dados.
    void preencher(); // Pede para preencher.

    void setIdade(int idade); // Métodos. "void setXx" permite atualizar o valor na main.
    int getIdade();           // "get" pega o valor e permite printar.
}; 

Pessoa::Pessoa() { //Antes de main, no objeto.cpp
    nome = ""; 
    idade = 0; 
    sexo = '\0';
} // Inicializa zerado os valores dos atributos.

Pessoa::~Pessoa() {
    cout << "O objeto " << nome << " foi destruido.";
} // No fim, destrói objetos para evitar leaks.

void Pessoa::setIdade(idade) { this->idade = idade; } //Define o atributo na main.

int Pessoa::getIdade() { return idade; } // Printa o atributo.

Pessoa::Pessoa(const Pessoa & outra) { //'const' diz que o original não pode ser alterado.
    idade = outra.idade; | Pega o valor do objeto e cria outro com o mesmo valor.
    nome = outra.nome;
}

void Pessoa::copiar(const Pessoa& outro) {
    idade = outro.idade; | Pega o valor do objeto e coloca em um ja criado.
    nome = outro.nome;
}

void Pessoa::imprimir() { //Imprime os atributos.
    cout << "Nome: " << nome << endl;
    cout << "Idade: " << idade << endl;
}

void Pessoa::preencher() {
    cout << "Nome: "; cin >> nome;
    cout << "Idade: "; cin >> idade;
}

void Pessoa::copia(Pessoa outra) { //Para ListaContigua.
    this->nome = outra.getNome();
    this->idade = outra.getIdade();
    this->sexo = outra.getSexo();
} //Copia o atributo do proximo elemento.