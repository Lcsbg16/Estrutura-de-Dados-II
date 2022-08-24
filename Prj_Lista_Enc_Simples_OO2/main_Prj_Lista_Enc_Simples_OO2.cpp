#include "Lista.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){ 
		cout << "\n************************" << endl;
		cout << "\t  MENU" << endl;
		cout << "************************" << endl;		
		cout << "1 - Insere inicio" << endl;
		cout << "2 - Insere Fim" << endl;			
		cout << "3 - Imprime" << endl;
		cout << "4 - Size" << endl;
		cout << "5 - Busca elemento na lista" << endl;
		cout << "6 - Retira elemento na lista" << endl;
		cout << "7 - Retira Inicio" << endl;
		cout << "8 - Retira Fim" << endl;
		cout << "9 - Imprime Inicio" << endl;
		cout << "10 - Imprime Fim" << endl;										
		cout << ">";

	}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	//MELHORAR A INTERFACE COM MENU PARA OS MÉTODOS EM TESTE DE CLASSE LISTA
	
	cout << "PROGRAMA LISTA ENCADEADA SIMPLES\n";
	Lista l; //instanciando objeto l conforme a classe Lista
	int op=1,x;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1: 
				cout << "Insira um numero inicio: ";
				cin >> x;
				l.insere_inicio(x);
				break;
			case 2:
				cout << "Insira um numero para ser inserido no fim: ";
				cin >> x;			
				l.insere_fim(x);	
				break;				

			case 3:
				l.imprime();
				break;				

			case 4: 
				l.tamanho();
				break;			
			case 5:
				cout << "Insira um numero para ser buscado: ";
				cin >> x;			
				l.busca(x);	
				break;				

			case 6:
				cout << "Insira um numero para ser retirado: ";
				cin >> x;			
				l.retira(x);	
				break;				

			case 7:		
				l.retira_inicio();	
				break;
			case 8: 
				l.retira_fim();
				break;			

			case 9: 
				l.imprime_inicio();
				break;				
	
			case 10: 
				l.imprime_fim();
				break;																																		
		}
	}while(op>0 && op<=10);
	
}
