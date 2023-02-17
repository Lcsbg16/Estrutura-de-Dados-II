#include "abb.h"
#include <conio.h>
using namespace std;

/* Prof. Irineu - Est. de Dados
Projeto de base para implementa��o de �rvore Bin�ria de Busca (AVL). Sup�e-se:
- main.cpp: front-end com usu�rio;
- abb.h e abb.cpp: prototipa��o OO de m�todos de manipula��o da �rvore bin�ria de busca (abb),
 contendo defini��o "struct" do n�-dado (campos info, filho_esquerda e filho_direita; como 
 tamb�m os m�todos de manipula��o como biblioteca OO.
Dica: refer�ncia de muitos m�todos em: 
 https://www.ic.unicamp.br/~rocha/teaching/2016s1/mc202/aulas/arvore-binaria-busca-01.pdf  
 Livro Robert Lafore, ED e Alg em Java - Ci�ncia Moderna, 2004.
Obs.: Recursos e m�todos adicionais � biblioteca dever�o ser desenvolvidos com base neste modelo.
*/
 
//fun��o de interface com o usu�rio, apenas para facilitar mensagens sobre o estado da �rvore 
void mensagem_arvore_vazia(bool t){
	cout << "�rvore est� ";
	if(t)
		cout << "vazia\n";
	else
		cout << "n�o-vazia\n";
}



void menu(){
	printf("----------------------------------");
	printf("\n\tPROGRAMA �RVORE BIN�RIA DE BUSCA OO\n");
	printf("----------------------------------");
	printf("\nEscolha uma das opcoes abaixo de ordenacao:");
	printf("\n1.Insere");
	printf("\n2.Imprime");
	printf("\n3.Busca");
	printf("\n4.Quantidade de Nos na Arvore");
	printf("\n5.Imprime em Ordem");
	printf("\n6.Imprime em Pre-Ordem");
	printf("\n7.Imprime em Pos-Ordem");		
	printf("\n8.Nivel da Arvore");	
	printf("\n9.Retira Valor");
	printf("\n10.Balancear Arvore");	
	printf("\n11.Reinicia");
	printf("\n12.Sair");

	printf("\n>");
}

int main(int argc, char** argv) {
	
	setlocale(LC_ALL, "Portuguese");
	int op,x;
	ArvBB tree; //instancia objeto conforme a classe, construtor faz root = NULL
	
	do{
		menu();
		scanf("%d",&op);		
		switch(op){
			case 1:
				printf("Informe um valor para ser inserido na arvore:");
				scanf("%d",&x);
				tree.insere(x);
				break;
			case 2:
				cout << "Mostrando estrutura de �rvore:\n";
				tree.displayTree();	
				break;
			case 3:
				printf("Informe um valor para ser buscado na arvore:");
				scanf("%d",&x);
				tree.busca(x);
				break;
			case 4:
				tree.QtdNodos();	
				break;	
			case 5:
				tree.exibirEmOrdem(tree.getRoot());
				printf("\n");
				break;		
			case 6:
				tree.exibirPreOrdem(tree.getRoot());
				printf("\n");
				break;	
			case 7:
				tree.exibirPosOrdem(tree.getRoot());
				printf("\n");
				break;	
			case 8:
				printf("O nivel da arvore � de %d\n",tree.nivel()+1);
				break;									
			case 9:
				printf("Informe um valor para ser retirado da arvore:");
				scanf("%d",&x);
				tree.retira(x);
				break;
			case 10:
				tree.balancear(tree.getRoot());
				break;											
			case 11:
				cout << "Liberando a estrutura de �rvore:\n";
				tree.reiniciaTree();
				break;
				
			default:
				printf("Opcao invalida");			
		
		}
	}while(op>0 && op<12);
	
	/*cout << "Inserindo dados na �rvore...\n";	
	tree.insere(5); 
	//tree.displayTree(); getch();
	tree.insere(2); getch();
	//tree.displayTree(); getch();
	tree.insere(3); 
	//tree.displayTree(); getch();
	tree.insere(1); 
	//tree.displayTree(); getch();
	tree.insere(9); 
	//tree.displayTree(); getch();
	tree.insere(7); 
	//tree.displayTree(); getch();
	tree.insere(8); 
	//tree.displayTree(); getch();
	tree.insere(10); 
	//tree.displayTree();	getch();			
	
	tree.displayRoot();
	
	cout << "Mostrando estrutura de �rvore:\n";
	tree.displayTree();
	mensagem_arvore_vazia(tree.vazia());

	cout << "Reiniciando a �rvore!\n";
	tree.reiniciaTree();
	mensagem_arvore_vazia(tree.vazia());
	tree.displayTree();
	
	tree.displayRoot();
	
	cout << "Inserindo dados na �rvore...\n";	
	tree.insere(9); 
	tree.insere(1); 
	tree.insere(11); 
	tree.insere(2); 
	tree.insere(4); 
	tree.insere(9); 
	cout << "Mostrando estrutura de �rvore:\n";
	tree.displayTree();
	mensagem_arvore_vazia(tree.vazia());*/
	
	cout << "Fim de programa!" << endl;
	tree.~ArvBB(); //destrutor da �rvore
	cout << "�rvore destru�da (desalocada)\n";
	system("pause");

	return 0;
}
