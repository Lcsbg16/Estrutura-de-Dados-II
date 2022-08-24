//Prof. Irineu - ED
#include <iostream>
#include <locale> //habilitar padrões de caracter de teclado PTb
#include "Calculadora_OO.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){
	cout << "Escolha opção:\n";
	cout << "1- Soma" << endl;
	cout << "2- Subtração" << endl;
	cout << "3- Multiplicação" << endl;
	cout << "4- Divisão" << endl;
	cout << "5- Raiz Quadrada" << endl;
	cout << "6- Potenciação" << endl;
	cout << "Qq outra para sair.\n";
	cout << "Opção: ";
}

float ler_numero(int i){
	cout << "Informe N" << i <<": ";
	float tmp;
	cin >> tmp;
	return tmp;
}

void mostra_resultado(float res){
	cout << "Resultado: " << res << endl;
}

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
//TESTE INICIAL	
//	Calculadora_OO teste; //criando objeto teste conforme a classe Calculadora_OO
//	
//	teste.n1 = 4;
//	teste.n2 = 6;
//	cout << "teste->n1: " << teste.n1 << " | teste->n2: " << teste.n2 << endl;
//	cout << "Soma: " << teste.soma() << endl;
//	
//	Calculadora_OO teste2(5, 0);
//	cout << "teste2->n1: " << teste2.n1 << " | teste2->n2: " << teste2.n2 << endl;
//	cout << "Soma: " << teste2.soma() << endl;
	
	//teste 2 - teste de menu com usuário	
	//criar condições de calcular operações aritméticas entre n1 e n2...
	Calculadora_OO teste; //cria objeto teste usando o construtor polimórfico sem parâmetros
	
	int op(1);
	float n1, n2;
	do{
		//1- apresentar menu de opções p escolha de operações: 1-soma,2-subtração,3-multiplicação,4-divisão
		menu();
		cin >> op;
		//2- ler opção e chamar a função desejada na bib calculadora - passar n1 e n2... back-end
		switch(op){
			case 1: //soma
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(teste.soma(n1, n2));
				break;
			case 2: //subtração
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(teste.subtracao(n1, n2));
				break;
			case 3: //multiplicação
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(teste.multiplicacao(n1, n2));
				break;
			case 4: //divisão
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(teste.divisao(n1, n2));
				break;
			case 5: //raiz
				n1 = ler_numero(1);
				mostra_resultado(teste.raiz(n1));
				break;
			case 6: 				
				n1 = ler_numero(1);
				n2 = ler_numero(2);
				mostra_resultado(teste.pot(n1, n2));
				break;					
			default: cout << "Opção inválida e fim de programa!\n";	//3- apresentar resultado / melhoria no front-end	
		}
	}while(op>=1 && op<=6);
	
	cout << "Fim de programa!\n";
	system("pause");
	return 0;
}
