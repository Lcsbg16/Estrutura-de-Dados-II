#include "Ordenacao.h"

Vetor::Vetor(){
	this->tamanho=0;
	this->vetor=(int *)malloc(this->tamanho*sizeof(int));

}




void Vetor::criavetor(int tamanho){
	srand(time(NULL));
	this->tamanho=tamanho;
	this->vetor=(int *)malloc(this->tamanho*sizeof(int));
	for(int i =0;i<this->tamanho;i++){
		this->vetor[i] = rand() % 9999;
	}

}


//	Bubble Sort
void Vetor::bubbleSort()
{
	int k, j, aux;
	int* vcopia=(int*) malloc(this->tamanho * sizeof(int));
	for(int i=0;i<this->tamanho;i++){
		vcopia[i]=this->vetor[i];
	}
	
	for(k=0;k<this->tamanho;k++)
	{
		for(j=0;j<this->tamanho-1;j++)
		{
			if(vcopia[j]>vcopia[j+1])
			{
				aux=vcopia[j];
				vcopia[j]=vcopia[j+1];
				vcopia[j+1]=aux;
			}
		}
	}
}
void Vetor::TempoBubble()
{
	clock_t inicio = clock();
	bubbleSort();
	clock_t fim = clock();
	double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Bubble Sort - Tempo: %f segundos\n\n\n", tempo);
}



//	Select Sort
void Vetor::selectSort() {
	int* vcopia=(int*) malloc(this->tamanho * sizeof(int));
	for(int i=0;i<this->tamanho;i++){
		vcopia[i]=this->vetor[i];
	}
		
    for (int i=0;i<this->tamanho;++i) {
        int iMenor=i;
        for (int iNext = i+1; iNext < this->tamanho; ++iNext) {
            if (vcopia[iNext] < vcopia[iMenor]) {
                iMenor = iNext;
            }
        }
        int aux = vcopia[i];
        vcopia[i] = vcopia[iMenor];
        vcopia[iMenor] = aux;
    }
}


void Vetor::TempoSelect()
{
	clock_t inicio = clock();
	selectSort();
	clock_t fim = clock();
	double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Select Sort - Tempo: %f segundos\n\n\n", tempo);
}

//	Insertion Sort

void Vetor::insertionSort(){
	int* vcopia=(int*) malloc(this->tamanho * sizeof(int));
	for(int i=0;i<this->tamanho;i++){
		vcopia[i]=this->vetor[i];
	}
		
    for (int i = 1; i < this->tamanho; i++) {
		int escolhido = vcopia[i];
		int j = i - 1;
		while ((j >= 0) && (vcopia[j] > escolhido)) {
			vcopia[j + 1] = vcopia[j];
			j--;
		}
		vcopia[j + 1] = escolhido;
	}	
}


void Vetor::TempoInsertion()
{
	clock_t inicio = clock();
	insertionSort();
	clock_t fim = clock();
	double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Insert Sort - Tempo: %f segundos\n\n\n", tempo);
}



//	Quick Sort
void Vetor::quickSort(int* vcopia,int began, int end)
{
	int i, j, pivo, aux;
	i = began;
	j = end-1;
	pivo = vcopia[(began + end) / 2];
	while(i <= j)
	{
		while(vcopia[i] < pivo && i < end)
		{
			i++;
		}
		while(vcopia[j] > pivo && j > began)
		{
			j--;
		}
		if(i <= j)
		{
			aux = vcopia[i];
			vcopia[i] = vcopia[j];
			vcopia[j] = aux;
			i++;
			j--;
		}
	}
	if(j > began)
		quickSort(vcopia, began, j+1);
	if(i < end)
		quickSort(vcopia, i, end);
}
void Vetor::TempoQuick()
{
	int* vcopia=(int*)malloc(this->tamanho*sizeof(int));
	for(int i=0;i<this->tamanho;i++){
		vcopia[i]=this->vetor[i];
	}
		
	clock_t inicio = clock();
	quickSort(vcopia,0, this->tamanho);
	clock_t fim = clock();
	double time = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Quick Sort - Tempo: %f segundos\n\n\n", time);
}


// Shell Sort
void Vetor::shellSort()
{
	int* vcopia=(int*) malloc(this->tamanho * sizeof(int));
	for(int i=0;i<this->tamanho;i++){
		vcopia[i]=this->vetor[i];
	}	
    int i, j, value;
    int h = 1;
    while(h < tamanho) {
        h = 3*h+1;
    }
    while (h > 0) {
        for(i = h; i < this->tamanho; i++) {
            value = vcopia[i];
            j = i;
            while (j > h-1 && value <= vcopia[j - h]) {
                vcopia[j] = vcopia[j - h];
                j = j - h;
            }
            vcopia[j] = value;
        }
        h = h/3;
    }
}

void Vetor::TempoShell()
{
	clock_t inicio = clock();
	shellSort();
	clock_t fim = clock();	
	double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Shell Sort - Tempo: %f segundos\n\n\n", tempo);
}


//	Merge Sort
void Vetor::mergeSort(int* vetor, int l, int r, int* vcopia)
{
	
	if(r > l)
	{
		int i, m = (l + (r - 1)) / 2;
		
		mergeSort(vetor,l,m,vcopia);
		mergeSort(vetor, m + 1, r,vcopia);
		merge(vetor, l, m, r,vcopia);
	}
}

void Vetor::merge(int* vetor, int l, int m, int r, int* vcopia){
	int i, j, k;
	int indice1 = m - l + 1;
	int indice2 = r - m;
	int vetTEMP1[indice1], vetTEMP2[indice2];
	for (i = 0; i < indice1; i++)
	{
		vetTEMP1[i] = vetor[l + i];
	}
	
	for (j = 0; j < indice2; j++)
	{
		vetTEMP2[j] = vetor[m + 1+ j];
	}
	
	i = 0;
	j = 0;
	k = l;
	
	while (i < indice1 && j < indice2)
	{
		if (vetTEMP1[i] <= vetTEMP2[j])
		{
			vcopia[k] = vetTEMP1[i];
			i++;
		}
		else
		{
			vcopia[k] = vetTEMP2[j];
			j++;
		}
		k++;
	}
	while (i < indice1)
	{
		vcopia[k] = vetTEMP1[i];
		i++;
		k++;
	}
	while (j < indice2)
	{
		vcopia[k] = vetTEMP2[j];
		j++;
		k++;
	}
}

void Vetor::TempoMerge(){
	
	int* vetor1 = (int*) malloc(this->tamanho * sizeof(int));
	for (int p=0; p < this->tamanho; p++){
        vetor1[p] = this->vetor[p];
    }	
	
	int* vetor2 = (int*) malloc(this->tamanho * sizeof(int));
	
	clock_t inicio = clock();
	mergeSort(vetor1,0,this->tamanho, vetor2);
	clock_t fim = clock();
	double tempo = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
	printf("\n Merge Sort - Tempo: %f segundos\n\n\n", tempo);
}

//	Radix Sort
void Vetor::radixSort() {
	int* vcopia=(int*) malloc(tamanho * sizeof(int));
	for(int i=0;i<tamanho;i++){
		vcopia[i]=this->vetor[i];
	}    
	int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tamanho, sizeof(int));

    for (i = 0; i < tamanho; i++) {
        if (vcopia[i] > maior)
    	    maior = vcopia[i];
    }
    while (maior/exp > 0) {
        int bucket[10] = { 0 };
    	for (i = 0; i < tamanho; i++)
    	    bucket[(vcopia[i] / exp) % 10]++;
    	for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	for (i = tamanho - 1; i >= 0; i--)
    	    b[--bucket[(vcopia[i] / exp) % 10]] = vcopia[i];
    	for (i = 0; i < tamanho; i++)
    	    vcopia[i] = b[i];
    	exp *= 10;
    }
    free(b);
}

void Vetor::TempoRadix()
{
	clock_t inicio = clock();
	radixSort();
	clock_t fim = clock();
	double tempo = (((double) (fim - inicio)) / CLOCKS_PER_SEC);
	printf("\n Radix Sort - Tempo: %f segundos\n\n\n", tempo);
}

