//abb.h
//Define a classe e protótipo de métodos OO para biblioteca de árvore binária de busca (abb)
//Por Irineu Lima, ED2 - FeMASS

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> //aplicada para função abb_displayTree - contâiner C++ LIFO
#include "no_dado.h"
using namespace std;
/*
struct noArv  //definição struct para nó-dado de árvore binária de busca
{
	int info;
	struct noArv* esq; //ponteiro para filho à esquerda
	struct noArv* dir; //ponteiro para filho à direita
};
typedef struct noArv NoArv; //definição de tipo para nó-dado de árvore binária de busca

*/


class ArvBB{
	//Declarar atributos
	//public:
	private:
		NoArv* root; //controle de ponteiro para nó-dado raiz
		int qtd;
	
	//Declarar cabeçalhos de métodos
	public:
		ArvBB(); //Construtor - método de mesmo nome da classe, não se usa a previsão de retorno
		~ArvBB(); //Destrutor - método executado ao fim ou término de uso do objeto de classe
		void insere(int v);
		void displayTree();
		NoArv* getRoot();
		void reiniciaTree();
		bool vazia();
		void displayRoot();
		void busca(int v);
		void QtdNodos();
		int nivel();

		void exibirEmOrdem(NoArv* a);
		void exibirPreOrdem(NoArv* a);
		void exibirPosOrdem(NoArv* a);
		
		void retira(int v);
		
		void balancear(NoArv* a);
		
	private:
		NoArv* abb_criavazia();
		NoArv* abb_cria (int c, NoArv* e, NoArv* d);
		NoArv* abb_insere(NoArv* a, int v);
		NoArv* abb_libera(NoArv* a);
		bool no_abb_vazio(NoArv* a);
		NoArv* busca_valor(NoArv* a,int v);
		int abb_nivel(NoArv* a);
		NoArv* RetiraNo(NoArv* a,int v);
		
		void rotacaodireita(NoArv* a);
		void rotacaoesquerda(NoArv* a);
		void rotacaoesquerdadireita(NoArv* a);
		void rotacaodireitaesquerda(NoArv* a);
		int fb(NoArv* a);
		
		
}; //toda classe encerra com ; (padrão da linguagem)

