//lista2.h
//Prototipar a classe
//Lista.h
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <iostream>
#include "no_dado.h"

using namespace std;

//struct lista {
//	int info;
//	struct lista* prox;
//};
//typedef struct lista no_dado;


//Estruturar a classe Lista que terá os métodos de manipulação da lista simples, usando alocação
//de nó-dado struct lista (no_dado) dinamicamente
class Lista{
	//Declarar atributos
	private:
		no_dado* cabeca; //controle de nó-cabeça
		no_dado* cauda;
		int qtd; //guardar qtd de nós encadeados
		
	//Declarando métodos	
	public:
		Lista();
		//~Lista();
		void insere_ordenado(int i);
		void retira_inicio();
		void retira_fim();	
		void retira(int i);					
		void imprime_inicio_fim();
		void imprime_fim_inicio();
		void busca_valor(int i);			
		/*
		*/
	private:
		bool isEmpty(no_dado* l);//método privado que auxiliará verificação de lista vazia a partir de um ponteiro	
};

