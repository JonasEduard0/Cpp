#include <iostream>
#include <locale.h>

using namespace std;

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

	int n1{ 10 }, n2{ 20 }, resul;
	cout << n1 << n2;
	n1 = n2++;
	cout << n1 << n2++;
	n1 = --n2;
	cout << n1 << --n2 << "\n" << flush()

	system("PAUSE");return 0;}
