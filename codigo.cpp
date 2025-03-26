#include <iostream>
#include <locale.h>
#include <string>
#include <cmath>
#include <vector>
#include <ctime>
#include "funcoesmenu.h"

using namespace std;

int funcaosomaumnumero(int somado1, int somado2) {
	return somado1 + somado2;}
void funcaovazio() {
	std::cout << "Void vazio";}

int varglobal = 100;


class classecasa
{
private:
	int numquarto{ 4 };
	float tamanho{ 90.0f };
	bool btemsuite{ true };

public:
	void mostratamanho();
	int obternumquarto();
	bool temsuite();
};


struct Data
{	public:
	int dia;
	int mes;
	int ano;
};

struct ponto3D
{
	int x, y, z;
	void desenhaponto3D(ponto3D pontos) {
		cout << "X: " << pontos.x << "  Y: " << pontos.y << "  Z: " << pontos.z;
	}
};


int main()
{
	setlocale(LC_ALL, "portuguese");

	typedef int numinteiro;
	std::cout << "Códigos em C++" << endl << "\n";
	system("color 0A");

	numinteiro vida = 5;
	const float pontuacao = 1350.50;
	vida = vida -1 +1 /2 *2;

	printf("Vidas: "); cout << vida << endl;
	cout << "Endereço que a var Vida ocupa na memória: " << &vida << "\n";
	cout << "Quantos bites pesa a var Vida: " << sizeof(vida) << endl << "\n";

	int numero1, numero2;
	cout << "Digite 2 números separados por espaço: ";
	std::cin >> numero1 >> numero2;
	cout << "Número 1 = " << numero1 << "\n" << "Número 2 = " << numero2 << endl << "\n";

	double number;
	cout << "Digite um número: ";
	cin >> number;
	bool Maiorque100;
	Maiorque100 = (number > 100);
	cout << "Se 0, seu número é < 100, se 1, >: " << Maiorque100 << endl;
	cout << "Seu número está entre 50 e 150?: " << (number >= 50) && (number <= 150);
	cout<< "\nEle é igual a 0?: " << !(number != 0)<<endl;

	char caractere{ 'c' };
	std::string Texto{ "Texto string" };
	double real = 11.123;
	const float flutuante(10.50);
	const int inteiro = 12;
	printf("\nNumero inteiro: %d, flutuante: %.2f, double: %.3lf, caractere: %c, string: %s\n", inteiro, flutuante, real, caractere, Texto.c_str());
	cout << "Numero inteiro: " << inteiro << ", flutuante: " << flutuante << ", double: " << real << ", caractere: " << caractere << ", string: " << Texto << endl << "\n";

	int n1{ 10 }, n2{ 20 };
	cout << n1 << " " << n2 << " ";
	n1 = n2++;
	cout << n1 << " " << n2++ << " ";
	n1 = --n2;
	cout << n1 << " " << --n2<<" ";

	string nome;
	int senha;
	cout << "\n\nDigite seu nome: ";
	cin >> nome;
	if (nome == "Jonas")
	{
		cout << "Esse é meu nome! \n\n";
		cout << " Digite a senha: ";
		cin >> senha;
		if (senha == 123 && nome == "Jonas")
		{
			cout << "Senha correta! \n\n";
		}
	}
	else if (nome == "Eduardo") {
		cout << "Apenas o primeiro nome, tente novamente.\n\n";
	}
	else {
		cout << "Não é meu nome \n\n";
	}

	int ot;
	cout << "Digite um inteiro: ";
	cin >> ot;
	ot > 5 ? cout << "Esse número é maior q 5\n\n" : cout << "Esse número é menor que 5\n\n";
	int maior = ot > 10 ? ot : 10;
	cout << maior << "\n\n";

	char escolet;
	cout << "Escolha um letra de 'a' ou 'b': ";
	cin >> escolet;
	switch (escolet)
	{
	case 'a' : cout << "Escolheu a!\n\n";
		break;
	case 'b' : cout << "Escolheu b!\n\n";
		break;
	default: cout << "a ou b não foram escolhidos.\n\n";
		break;
	}

	int contador = 0;
	while (contador <= 10) {
		cout << contador << " ";
		contador++;
		}
	cout << "\n\n";

	int dw{ 11 };
	do
	{
		cout << dw << " ";
		++dw;
	} while (dw<10);
	cout << "\n\n";

	int soma = 0;
	for (int i = 1; i <= 10; i++)
	{
		soma = soma + i;
	}
	cout << "A soma dos números de 1 a 10 é " << soma << "\n\n";

	int somado1 = 5, somado2 = 10;
	cout << "A soma da função é: " << funcaosomaumnumero(somado1, somado2) << "\n\n";

	static string VarEstatica = "Variável Estática";

	int apontado{ 4096 };
	int* ptr = &apontado;
	cout << "Valor da variável 'apontado': " << apontado << "\n";
	cout << "Valor da variável ptr: " << ptr << "\n";
	cout << "Endereço de apontado: " << &apontado << "\n";
	cout << "Endereço de ptr: " << &ptr << "\n";
	cout << "Valor contida na variável apontada por ptr: " << *ptr << "\n\n";

	int gen{ 4890 };
	char g{ 'E' };
	void* ptrg;
	ptrg = &g;
	cout << "Valor de 'letra' via ptrg: " << *(char*)ptrg;

	int referenciado{ 1024 };
	char r{ 'A' };
	int& referenciador = referenciado;
	cout << "\nValor de referenciado usando referência: " << referenciador << "\n";
	cout << "Valor endereço do referenciado: " << &referenciado << "\n";
	cout << "Valor endereço do referência: " << &referenciador << "\n\n";

	float array[5]{1.0f,2.0f,3.0f,4.0f,5.0f};
	int i = 1;
	array[0] = 10.0f;
	array[i + 1] = 9.8f;
	array[1] = 8.0f;
	array[3] = array[0] - 3;
	float media{ (array[0] + array[1] + array[2] + array[3] + array[4]) / 5 };
	cout << media << "\n\n";
	
	int matriz[5][5];
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			if (i<j)
			{
				cout << " 1 ";
			}
			else if (i == j) {
				cout << " 0 ";
			}
			else{
				cout << "-1 ";
			}
		}
		cout << "\n";
	}
	cout << matriz<<"\n\n";

	int foreache[]{ 10,20,30,40,50 };
	for (auto a : foreache)
	{
		cout << a << " ";
	}
	cout<<"\n\n";

	vector<float>vetordinamico = {1,2,3};
	vetordinamico.push_back(4);
	for (auto a : vetordinamico)
	{
	cout << a << "\n";
	}

	int vetpont[]{ 1,23,-78,900,234 };
	int* pontvet = vetpont;
	for (int i = 0; i < 5; i++)
	{
		cout << pontvet[i] << " "; // = *(vetpont + 1)
	}


	classecasa casadepraia;
	casadepraia.mostratamanho();
	cout << "\n" << casadepraia.obternumquarto();
	cout << "\n" << casadepraia.temsuite() << "\n";

	class apartamento : private classecasa{};


	/*Data agenda = {22, 07, 2013};
	agenda.dia = 22;
	agenda.mes = 07;
	agenda.ano = 2013;
	cout << "Dia: " << agenda.dia << "  Mês: " << agenda.mes << "  Ano: " << agenda.ano;*/

	string perg;cout << "\n\nDeseja limpar o console? (Sim/Não): ";cin >> perg;if (perg == "Sim" or perg == "sim") { system("Clear || CLS"); }
	else if (perg == "Não" or perg == "nao" or perg == "Nao" or perg == "não") { cout << "Não será limpado\n"; }system("PAUSE");return 0;}


void classecasa::mostratamanho()
{
	cout << "\nTamanho: " << tamanho;
}

int classecasa::obternumquarto()
{
	return numquarto;
}

bool classecasa::temsuite() {
	return btemsuite;
}
