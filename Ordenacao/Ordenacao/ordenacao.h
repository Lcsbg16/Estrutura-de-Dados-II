#include <stdio.h>
#include <cstring>
#include <stdlib.h>
#include <time.h>

class Vetor{
	private: int tamanho;
			int* vetor;
	public:
		Vetor();
		void inicializa(int* vetor);
		void criavetor(int tamanho);
		
		

		void bubbleSort();
		void TempoBubble();
		
		void selectSort();
		void TempoSelect();
		
		void insertionSort();
		void TempoInsertion();
		
		void quickSort(int* vcopia,int began, int end);
		void TempoQuick();
		
		void shellSort ();
		void TempoShell();
		
		void mergeSort(int* vetor, int l, int r,int* vcopia);
		void merge(int* vetor, int l, int m, int r,int* vcopia);
		void TempoMerge();
		
		
		void radixSort();
		void TempoRadix();
};


