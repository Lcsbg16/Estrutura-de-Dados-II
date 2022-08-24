//Desenvolver métodos de classe
//Lista.cpp

#include "Lista.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->qtd = 0;
}

//destrutor
Lista::~Lista(){
	this->libera(); //ideia é liberar free toda memória alocada
	this->qtd = 0;
}

void Lista::insere_inicio(int i){
	//no_dado* novo = (no_dado*) malloc(sizeof(no_dado));
	//novo->info = i;
 	//novo->prox = this->cabeca;
 	no_dado* novo = new no_dado(i, this->cabeca);
  	this->cabeca = novo; //adiciona a partir do início
  	this->qtd++; //incrementa o contador de nó-dado
}
void Lista::insere_fim(int i){
	if(this->isEmpty(this->cabeca)){
		no_dado* novo = new no_dado(i, this->cabeca);
  		this->cabeca = novo; //adiciona a partir do início
  		this->qtd++;	
	}
	else{
		no_dado* novo = new no_dado(i, this->cabeca);
		no_dado* p;
		for (p = this->cabeca; p->prox != NULL; p = p->prox);
		p->prox = novo;	
		novo->prox=NULL;	
		this->qtd++;
	}	
}
void Lista::imprime(){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		printf("Info = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("Lista está vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista não está vazia!\n");
	else
		printf("Lista está vazia!\n");
}

void Lista::libera(){
	no_dado* p = this->cabeca;
	 while (p != NULL) {
	 	no_dado* t = p->prox; // guarda referência para o próximo elemento
		free(p); /* libera a memória apontada por p */
		this->qtd--; //decrementa contador de qtd
	 	p = t; /* faz p apontar para o próximo */
	 }
	 this->cabeca = 0; //inicializa lista vazia
}

void Lista::tamanho(){
	printf("Tamanho ou qtd de elementos: %d\n", this->qtd);
}


void Lista::busca(int i){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* variável auxiliar para percorrer a lista */
		int achou=0;
		for (p = this->cabeca; p != NULL; p = p->prox){
			if(p->info==i)
				achou=1;
		}
		if (achou == 1){
			printf("Elemento Encontrado!\n");
		}
		else{
			printf("Elemento Nao Encontrado!\n");	
		}	
	} else printf("Lista está vazia!\n");
}

void Lista::retira(int i){
	
	no_dado* ant = NULL;
	no_dado* p = this->cabeca;
	
	while (p != NULL && p->info != i){
		
		ant = p;
		p = p->prox;
	}
	
	if (p == NULL){
		
		cout << "Lista vazia!" << endl;
	}
	
	if (ant == NULL){
		
		this->cabeca = p->prox;
		this->qtd--;
	}
	else
	{
		ant->prox = p->prox;
		this->qtd--;
	}
	
	free(p);
}

void Lista::retira_inicio(){
	if(!this->isEmpty(this->cabeca)){	
	no_dado* p=this->cabeca;
	this->cabeca=p->prox;
	this->qtd--;
	printf("Elemento retirado no inicio:%d",p->info);
	free(p);	
	}
	else{
		printf("A lista ja esta vazia, nao eh possivel remover!");
	}	
	
}

void Lista::retira_fim(){
	if(!this->isEmpty(this->cabeca)){	
	no_dado* p=this->cabeca;
	no_dado* ant=NULL;
	while(p->prox!=NULL){
		ant=p;
		p=p->prox;
	}
	if(ant==NULL){
		this->cabeca=p->prox;
	}
	else{
		ant->prox=p->prox;
	}
	
	this->qtd--;
	printf("Elemento retirado no fim:%d",p->info);
	free(p);	
	}
	else{
		printf("A lista ja esta vazia, nao eh possivel remover!");
	}	
	
}	

void Lista::imprime_inicio(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p=this->cabeca;
		printf("Inicio: %d",p->info);
	}
	else{
		printf("A lista ja esta vazia!");
	}
}

void Lista::imprime_fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p=this->cabeca;
		for(p=this->cabeca;p->prox!=NULL;p=p->prox);
		printf("Fim: %d",p->info);
	}
	else{
		printf("A lista ja esta vazia!");
	}
}

//tratamento métodos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}


