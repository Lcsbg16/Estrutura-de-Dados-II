#include "Ordenacao.h"


void menu(){
	printf("----------------------------------");
	printf("\n\tAlgoritmo de Ordenacao\n");
	printf("----------------------------------");
	printf("\nEscolha uma das opcoes abaixo de ordenacao:");
	printf("\n1.Bubble Sort");
	printf("\n2.Insert Sort");
	printf("\n3.Selection Sort");
	printf("\n4.Quick Sort");
	printf("\n5.Shell Sort");
	printf("\n6.Merge Sort");
	printf("\n7.Radix Sort");
	printf("\n8.Todos Juntos");
	printf("\n9.Imprimir vetor ordenado");
	printf("\n10.Sair");

	printf("\n>");
}

int main()
{
	//Vetor v;
	
	int tamanho = 0;
	int op;
	printf("Digite o tamanho do vetor: ");
	scanf(" %d", &tamanho);
	
	Vetor vetor;
	vetor.criavetor(tamanho);
	
	do{
		
		menu();
		scanf("%d",&op);		
		switch(op){
			
			case 1: //Bubble Sort
				vetor.TempoBubble();
				break;
			
			case 2: //Selection Sort
				vetor.TempoSelect();
				break;	
			
			case 3: //Insertion Sort
				vetor.TempoInsertion();
				break;
			
			case 4: //Quick Sort	
				vetor.TempoQuick();
				break;
			
			case 5://Shell Sort
				vetor.TempoShell();
				break;
			
			case 6: //Merge Short	
				vetor.TempoMerge();	
				break;		
			
			case 7: //Radix
				vetor.TempoRadix();
				break;	
			case 8:
				vetor.TempoBubble();												
				vetor.TempoSelect();
				vetor.TempoInsertion();
				vetor.TempoQuick();
				vetor.TempoShell();
				vetor.TempoMerge();
				vetor.TempoRadix();	
				break;
				
			default:
				printf("Saindo do Programa...");	
		}	
	}while(op>0 && op<10);
}
