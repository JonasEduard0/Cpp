#pragma once

#include <string>
#include <iostream>

using namespace std;

class Produto {
    int id;
    string nome;
    double custo;
    double preco;   
    int estoque; 
public:
    Produto(){ nome = ""; id = 0; custo = 0.0; preco = 0.0; estoque = 1; };
    Produto(const Produto &outro);
    
    void imprimir();
    void preencher();
    
    void   setEstoque(int estoque){ this->estoque = estoque; };
    void   setCusto(double custo) { this->custo = custo; };
    void   setPreco(double preco) { this->preco = preco; };
    void   setId(int id) { this->id = id; };
    void   setNome(string nome) { this->nome = nome; };

    int    getEstoque() const { return estoque; };
    double getCusto() const { return custo; };
    double getPreco() const { return preco; };
    int    getId() const { return id; };
    string getNome() const { return nome; };
};

Produto::Produto(const Produto &outro) {
    this->nome = outro.nome;
    this->id = outro.id;
    this->custo = outro.custo;
    this->preco = outro.preco;
    this->estoque = outro.estoque;
}

void Produto::imprimir() {
    std::cout << "Nome: " << nome << std::endl;
    std::cout << "Id: " << id << std::endl;
    std::cout << "Custo: " << custo << std::endl;
    std::cout << "Preco: " << preco << std::endl;
    std::cout << "Estoque: " << estoque << std::endl;
}

void Produto::preencher() {
    std::cout << "Insira o nome: ";
    std::cin >> nome;

    std::cout << "Insira o id: ";
    std::cin >> id;

    std::cout << "Insira o custo: ";
    std::cin >> custo;

    std::cout << "Insira o preco: ";
    std::cin >> preco;

    std::cout << "Insira o estoque: ";
    std::cin >> estoque;
}