#pragma once
#include <iostream>
#include <string>

void exibirmenu();
int escolha();
void precessaescolha(int tipoescolha);

class conta
{
private:
	string banco;
	int agencia;
	int numconta;
	string titular;
	double saldo;
public:
	bool sacar(double valor);
	void depositar(double valor);
	void tranferir(conta& destino, double valor);
	double consultarsaldo();
	string getbanco();
	int getagencia();
	int getconta();
	string gettitular();
	void setbanco(string banco);
	void setagencia(int agencia);
	void settitular(string titular);
};