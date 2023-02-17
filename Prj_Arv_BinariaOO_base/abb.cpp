//abb.cpp
//Implementa os m�todos de classe prototipados no .h, biblioteca OO para �rvore bin�ria de busca (abb)
//Por Irineu Lima, ED2 - FeMASS

#include "abb.h"
#include <math.h>
//Obs.: a ordem de m�todos descritos segue a mesma ordem da prototipa��o da classe no arquivo abb.h
//>>>>>>>>>> M�todos P�blicos - chamdados pelo main de forma direta (p�blica) <<<<<<<<<

//construtor
ArvBB::ArvBB(){
	this->root = abb_criavazia(); //construtor faz a inicializa��o de �rvore vazia
}

//destrutor
ArvBB::~ArvBB(){
	reiniciaTree(); //chama m�todo privado capaz de desalocar n�s-dado alocados e apontados por root
}

//insere novo n�-dado
void ArvBB::insere(int v){
	if (this->root != NULL) 
		abb_insere(this->root, v); //inser��o de demais n�s-dado ap�s root
	else
		this->root = abb_insere(this->root, v); //primeiro n�-dado inserido, root
	this->qtd++;	
}

//Desenha a �rvore para exibi��o de n�s-dados contidos
void ArvBB::displayTree(){ //baseado em displayTree, p.371 - Livro Robert Lafore, ED e Alg em Java - Ci�ncia Moderna, 2004.
	NoArv* a = this->root; //inicia do root
	stack<NoArv*> globalStack; //uso de bib stack.h da STD lib (cont�iner C++ LIFO)
	globalStack.push(a);
	int nBlanks = 32;
	bool isRowEmpty = false;
	cout << "Vis�o encadeada de �rvore: " << endl;
	
	while (isRowEmpty == false){
		stack<NoArv*> localStack; 
		isRowEmpty = true;
	
		for (int j=0; j<nBlanks; j++)
			cout << " ";
	
		while (globalStack.empty()== false){
			NoArv* temp = globalStack.top(); //pega topo da pilha global e...
			globalStack.pop(); //...e o remove em seguida
			
			if (temp != NULL){
				cout << temp->info;
				localStack.push(temp->esq);
				localStack.push(temp->dir);
				
				if ((temp->esq != NULL) || (temp->dir != NULL)){
					isRowEmpty = false;
				}	
			}else{
				cout << "-";	
				localStack.push(NULL);
				localStack.push(NULL);	
			}
			int fim = nBlanks*2 - 1;
			for (int j=0; j<fim; j++)
				cout << " ";
		} //fim-while do globalStack n�o vazio
		cout << endl;
		nBlanks = nBlanks / 2;
		while (localStack.empty() == false){
			globalStack.push(localStack.top()); //pega topo da pilha local e...
			localStack.pop(); //...e o remove em seguida
		}
	} //fim-while do isRowEmpty � falso
	cout << endl;
}

//retorna o n�-dado root
NoArv* ArvBB::getRoot(){
	return this->root;	
}

//libera e desaloca todos os n�s da �rvore, reiniciando em Null o ponteiro root
void ArvBB::reiniciaTree(){
	this->root = abb_libera(this->root);
}

//retorna true/false se �rvore � vazia?
bool ArvBB::vazia(){
	return no_abb_vazio(this->root);
}

void ArvBB::displayRoot(){
	if (this->root != NULL) 
		cout << "Root -> info: " << this->root->info << endl;
	else
		cout << "�rvore vazia! \n";
}


void ArvBB::busca(int v){
	NoArv* a = this->root;
	if(busca_valor(a,v) != NULL){
		printf("Valor encontrado!\n");
	}else{
		printf("Valor n�o encontrado!\n");
	}
}


int ArvBB::QtdNodos(){
	return this->qtd;
}

void ArvBB::retira(int v){
	NoArv* a = this->root;
	if(RetiraNo(a,v) != NULL){
		printf("Valor encontrado e removido!\n");
		this->qtd--;
	}else{
		printf("Valor informado n�o existe na arvore!\n");
	}
	
}



int ArvBB::nivel(){
	NoArv* a = this->root;
	int nivel = abb_nivel(a);
	return nivel;
}


void ArvBB::exibirEmOrdem(NoArv* a){
    if(a != NULL){
        exibirEmOrdem(a->esq);
        printf("%d - ", a->info);
        exibirEmOrdem(a->dir);
    }
}

void ArvBB::exibirPreOrdem(NoArv* a){
	if (a != NULL) {
		printf("%d - ", a->info);
		exibirPreOrdem(a->esq);
		exibirPreOrdem(a->dir);
	}
}

void ArvBB::exibirPosOrdem(NoArv* a){
	if(a != NULL){
        exibirPosOrdem(a->esq);
        exibirPosOrdem(a->dir);
        printf("%d - ", a->info);
    }
}


void ArvBB::EmNivel(NoArv* a){	
    int al = abb_nivel(a);
    int i;
    for (i = 0; i<=al; i++) {
        abb_altura_atual(a, i);
    }
	
}


void ArvBB::AddToArray(NoArv *a, int arr[], int *i){
	if(a == NULL)
    	return ;
    arr[*i] = a->info;
    ++*i;
    AddToArray(a->esq, arr, i);
    AddToArray(a->dir, arr, i);
}


void ArvBB::balance(int arr[],int first,int last){
	if(first <= last){
		int middle = (first + last)/2;
		insere(arr[middle]);
		balance(arr,first,middle-1);
		balance(arr,middle+1,last);
	}
}






//>>>>>>>>>> M�todos Privados - em apoio e execu��o interna (privada) <<<<<<<<<

// m�todo de inicializa��o: retorna n� nulo (vazio) 
NoArv* ArvBB::abb_criavazia(){
	return NULL;
}

// m�todo de cria��o: retorna n� criado (alocado)
NoArv* ArvBB::abb_cria(int c, NoArv* sae, NoArv* sad){
	//NoArv* p=(NoArv*)malloc(sizeof(NoArv));
	NoArv* p = new NoArv(c, this->root);
	
	if(p==NULL){
		cout << "FALHA DE ALOCA��O EM MEM�RIA!\n";
		exit(1);
	} 
	p->info = c;
	p->esq = sae;
	p->dir = sad;
	return p;
}

//M�todo de controle de inser��o de novo n�-dado - garante l�gica de inser��o de ABB
NoArv* ArvBB::abb_insere(NoArv* a, int v){
	if (a == NULL) //primeira inser��o, insira n� root
		a = abb_cria (v, NULL, NULL);
	else if (v < a->info)
		a->esq = abb_insere(a->esq,v); //insere como filho � esquerda
	else /*sen�o, temos: v >= a->info */
		a->dir = abb_insere(a->dir,v); //insere como filho � direita
	return a;
}

//M�todo recursivo que desaloca n�s-dado da �rvore, retornando NULL
NoArv* ArvBB::abb_libera(NoArv* a){
	if (!no_abb_vazio(a)){
		abb_libera(a->esq); /* libera sae */
		abb_libera(a->dir); /* libera sad */
		free(a); /* libera raiz */
	}
	return NULL;
}

//M�todo que verifica se um n�-dado � nulo?
bool ArvBB::no_abb_vazio(NoArv* a){
	return a == NULL;
}

NoArv* ArvBB::busca_valor(NoArv* a,int v){
	if (a == NULL)
	 	return NULL;
	else if (a->info > v)
	 	return busca_valor(a->esq, v);
	else if (a->info < v)
	 	return busca_valor(a->dir, v);
	else return a;
}


NoArv* ArvBB::RetiraNo(NoArv* a, int v){
	if(a == NULL){
		return NULL;
	}else if( a->info > v){
		a->esq = RetiraNo(a->esq, v);
	}else if(a->info < v){
		a->dir = RetiraNo(a->dir, v);
	}else{
		if(a->esq == NULL && a->dir == NULL){
			free (a);
			a = NULL;
		}
		else if(a->esq == NULL){
			NoArv* t = a;
			a = a->dir;
			free(t);
		}
		else if(a->dir == NULL){
			NoArv* t = a;
			a = a->esq;
			free(t);
		}
		else{
			NoArv* f = a->esq;
			while (f->dir != NULL){
				f = f->dir;
			}
			a->info = f->info;
			f->info = v;
			a->esq = RetiraNo(a->esq,v);
		}
	}
	return a;
}


int ArvBB::abb_nivel (NoArv* a) {
    if (a != NULL) {
        int esquerda = abb_nivel(a->esq);
        int direita = abb_nivel(a->dir);
        if (esquerda > direita) {
            return (esquerda + 1);
        }
        else {
            return (direita + 1);
        }
    }
}

void ArvBB::abb_altura_atual(NoArv* a, int level) {
    if (a != NULL) {
        if (level == 1) {
            cout << "  " << a->info;
        }
        else if (level > 1) {
            abb_altura_atual(a->esq, level-1);
            abb_altura_atual(a->dir, level-1);
        }
    }
}








