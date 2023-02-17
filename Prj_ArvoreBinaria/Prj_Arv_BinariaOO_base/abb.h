//abb.h
//Define a classe e prot�tipo de m�todos OO para biblioteca de �rvore bin�ria de busca (abb)
//Por Irineu Lima, ED2 - FeMASS

#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stack> //aplicada para fun��o abb_displayTree - cont�iner C++ LIFO
#include "no_dado.h"
using namespace std;
/*
struct noArv  //defini��o struct para n�-dado de �rvore bin�ria de busca
{
	int info;
	struct noArv* esq; //ponteiro para filho � esquerda
	struct noArv* dir; //ponteiro para filho � direita
};
typedef struct noArv NoArv; //defini��o de tipo para n�-dado de �rvore bin�ria de busca

*/


class ArvBB{
	//Declarar atributos
	//public:
	private:
		NoArv* root; //controle de ponteiro para n�-dado raiz
		int qtd;
	
	//Declarar cabe�alhos de m�todos
	public:
		ArvBB(); //Construtor - m�todo de mesmo nome da classe, n�o se usa a previs�o de retorno
		~ArvBB(); //Destrutor - m�todo executado ao fim ou t�rmino de uso do objeto de classe
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
		
		
}; //toda classe encerra com ; (padr�o da linguagem)

