#include "Lista2.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->cauda=0;
	this->qtd = 0;
}



void Lista::insere_ordenado(int i){

 	no_dado* novo = new no_dado(i, this->cabeca);
  	this->cabeca = novo; //adiciona a partir do in�cio
  	
  	this->qtd++; //incrementa o contador de n�-dado


	if(this->isEmpty(this->cabeca)){
	novo->prox = NULL;
	novo->ant = NULL;
	l = novo;
	return l;
	}
	//Se n�o for vazia...
	else
	{
	Lista* p = l;
	//Inserir antes do primeiro n�-dado por ser menor que ele
	if (x < p->info)
	{
	novo->ant = NULL;
	novo->prox = l;
	l->ant = novo;
	l = novo;
	return l;
	}
	//Caso o valor inserido seja igual ao primeiro n� dado da lista
	else if ((x == p->info)&&(p->ant == NULL))
	{
	novo->prox = p;
	novo->ant = NULL;
	p->ant = novo;
	l = novo;
	return l;
	}
	//Se n�o for antes do primeiro n�-dado
	else
	{
	//Estrutura de repeti��o para percorrer a lista at� o lugar necess�rio para inser��o ordenada
	for (; x > p->info; p = p->prox)
	{
	//Caso tenha que inserir no �ltimo n�-dado
	if ((p->prox == NULL)&&(x > p->info))
	{
	novo->ant = p;
	p->prox = novo;
	novo->prox = NULL;
	return l;
	}
	//Caso o valor seja igual ao �ltimo n�-dado
	else if ((p->prox == NULL)&&(x == p->info))
	{
	p->prox = novo;
	novo->ant = p;
	novo->prox = NULL;
	return l;
	}
	}
	
	//Caso tenha que inserir em alguma posi��o entre o primeiro e o �ltimo n�-dado
	novo->ant = p->ant;
	novo->prox = p;
	p->ant->prox = novo;
	p->ant = novo;
	return l;
	}
	}
	}  	
  	
  	
  	
}
void Lista::insere_fim(int i){
	if(this->isEmpty(this->cabeca)){
		no_dado* novo = new no_dado(i, this->cabeca);
  		this->cabeca = novo; //adiciona a partir do in�cio
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
		no_dado* p; /* vari�vel auxiliar para percorrer a lista */
		printf("Info = ");
		for (p = this->cabeca; p != NULL; p = p->prox)
			printf("%d - ", p->info);
		printf("\n");	
	} else printf("Lista est� vazia!\n");
}

void Lista::vazia(){
	if (!this->isEmpty(this->cabeca))
		printf("Lista n�o est� vazia!\n");
	else
		printf("Lista est� vazia!\n");
}

void Lista::tamanho(){
	printf("Tamanho ou qtd de elementos: %d\n", this->qtd);
}


void Lista::busca(int i){
	if (!this->isEmpty(this->cabeca)){
		no_dado* p; /* vari�vel auxiliar para percorrer a lista */
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
	} else printf("Lista est� vazia!\n");
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

//tratamento m�todos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}


