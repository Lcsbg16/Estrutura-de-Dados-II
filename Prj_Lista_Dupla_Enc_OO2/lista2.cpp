#include "Lista2.h"

//construtor
Lista::Lista(){
	this->cabeca = 0; //inicializa lista vazia
	this->cauda=0;
	this->qtd = 0;
}



void Lista::insere_ordenado(int i)
{
	no_dado* p; // ponteiro para percorrer a lista
 	no_dado* novo = new no_dado(i, this->cabeca); //direciona o novo no como cabeca


 	if (this->isEmpty(this->cabeca)) //se cabeca for vazio
	{
		this->cabeca = novo; //cabeca = novo
		this->cauda = novo;
 	}
 	
 	else 
	if (this->cabeca->info     >=     novo->info)  //se info(cabeca) for maior/igual que info(novo)
	{	
	 	novo->prox = this->cabeca;
	 	
	 	novo->prox->ant = novo;
	 	
	 	this->cabeca = novo;
	}
	 
	else 
	{
	 	p = this->cabeca;	
	 	
	 	//enquanto prox não for NULO & prox(info) menor que o novo(info)
	 	while (p->prox != NULL     &&     p->prox->info   <     novo->info) //encontra o no anterior do inserido
		{
			p = p->prox;
	 	}
	 	
	 	novo->prox = p->prox; //prox(novo) = prox(p)
	 		 	
	 	//Se for inserido no final...
	 	if (p->prox != NULL) //se prox(p) nao for NULO ou ultimo...
		{
			novo->prox->ant = novo;
			p->prox = novo;
			novo->ant = p;
	 	}
	 	if(p->prox==NULL){//Insere no fim
	 		novo->ant=p;
	 		p->prox=novo;
	 		this->cauda=novo;
		 }	
	}
	this->qtd++;
}
void Lista::retira_inicio(){
	no_dado* p=this->cabeca;
	if (!this->isEmpty(this->cabeca)){
		if(p->prox==NULL && p->ant==NULL){
			printf("Unico Elemento Removido na Lista: %d",p->info);
			free(p);
			this->cabeca=NULL;
			this->cauda=NULL;
			this->qtd--;
		}
		else{
			this->cabeca=this->cabeca->prox;
			this->cabeca->ant=NULL;	
			printf("Elemento Removido no Inicio: %d",p->info);
			free(p);
			this->qtd--;					
		}
	}
	else{
		printf("Lista Vazia!");
	}
}

void Lista::retira_fim(){
	no_dado* p=this->cauda;
	if(!this->isEmpty(this->cabeca)){
		if(p->prox==NULL && p->ant==NULL){
			printf("Unico Elemento Removido na Lista: %d",p->info);
			free(p);
			this->cabeca=NULL;
			this->cauda=NULL;
			this->qtd--;			
		}else{
			this->cauda=p->ant;
			this->cauda->prox=NULL;
			printf("Elemento Removido no Final: %d",p->info);
			free(p);
			this->qtd--;
		}
	}
	else{
		printf("A lista ja esta vazia, nao eh possivel remover!");
	}	
}	
	


void Lista::retira(int i){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p;
		int achou=0;
	for (p = this->cabeca; p != NULL; p = p->prox)
	{
 		if (p->info == i)
 		{
			achou=1;
			break; 
 		}
 	}	
	 
	 	//Nao achou		
		if(achou==0){
			printf("Elemento nao encontrado!");
		}
		else{
			//Elemento Unico
			if(p->prox==NULL && p->ant==NULL){
				printf("Unico Elemento Removido na Lista: %d",p->info);
				free(p);
				this->cabeca=NULL;
				this->cauda=NULL;
			}
			
			
			//primeiro elemento
			if(p->prox!=NULL && p->ant==NULL){
				this->cabeca=this->cabeca->prox;
				printf("Elemento Removido no Inicio: %d",p->info);
				free(p);
			}
			
			//Ultimo elemento
			if(p->prox==NULL && p->ant!=NULL){
				this->cauda=this->cauda->ant;
				this->cauda->prox=NULL;
				printf("Elemento Removido no Final: %d",p->info);
				free(p);
			}
			
			//Elemento no meio
			if(p->prox!=NULL && p->ant!=NULL){
				p->ant->prox=p->prox;
				p->prox->ant=p->ant;
				printf("Elemento Removido no Meio: %d",p->info);
				free(p);
			}
		}
		
		this->qtd--;		
	}else printf("Lista está vazia!\n");	
}

	
void Lista::busca_valor(int i){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p;
		int achou;
		for(p=this->cabeca;p!=NULL;p=p->prox){
			if(p->info==i){
				achou=1;
				break;
			}
		}
		
		if(achou==1){
			printf("Elemento Encontrado!");
		}
		else{
			printf("Elemento Nao Existe na Lista!");
		}
		
	}
	else printf("Lista está vazia!\n");	
	
}




void Lista::imprime_inicio_fim(){
	if(!this->isEmpty(this->cabeca)){
		no_dado* p;
		printf("Info: ");
		for(p=this->cabeca;p!=NULL;p=p->prox){
			printf("%d - ",p->info);
		}
		printf("\n");	
	}else printf("Lista está vazia!\n");
	
	
}

void Lista::imprime_fim_inicio(){
	if (!this->isEmpty(this->cabeca))
	{
		no_dado* p = this->cauda;
		printf("info:");
		for(p = this->cauda;p!=NULL;p=p->ant){
			printf("%d - ",p->info);
		}
	}
	else
		printf("Lista eh vazia!");	
}


//tratamento métodos privados
bool Lista::isEmpty(no_dado* l){
	return l==NULL;
}



