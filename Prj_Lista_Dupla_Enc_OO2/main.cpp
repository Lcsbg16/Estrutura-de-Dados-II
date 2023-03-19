#include "Lista2.h"
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void menu(){ 
		cout << "\n************************" << endl;
		cout << "\t  MENU" << endl;
		cout << "************************" << endl;		
		cout << "1 - Insere Ordenado" << endl;
		cout << "2 - Retira Inicio" << endl;			
		cout << "3 - Retira Fim" << endl;
		cout << "4 - Retira elemento na lista" << endl;
		cout << "5 - Imprime Inicio->Fim" << endl;
		cout << "6 - Imprime Fim->Inicio" << endl;	
		cout << "7 - Busca elemento na lista" << endl;									
		cout << ">";

	}
int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	//MELHORAR A INTERFACE COM MENU PARA OS MÉTODOS EM TESTE DE CLASSE LISTA
	
	
	Lista l; //instanciando objeto l conforme a classe Lista
	int op=1,x;
	do{
		menu();
		scanf("%d",&op);
		switch(op){
			case 1: 
				cout << "Insira um numero : ";
				cin >> x;
				l.insere_ordenado(x);
				break;
			case 2:
				l.retira_inicio();	
				break;
			case 3:
				l.retira_fim();
				break;				

			case 4: 
				cout << "Insira um numero para ser retirado: ";
				cin >> x;			
				l.retira(x);	
				break;			
			case 5:
				l.imprime_inicio_fim();
				break;					

			case 6:
				l.imprime_fim_inicio();
				break;				

			case 7:		
				cout << "Insira um numero para ser buscado: ";
				cin >> x;			
				l.busca_valor(x);		
				break;											
			default:
				printf("Opcao invalida!");																																		
		}
	}while(op>0 && op<8);
	
}
