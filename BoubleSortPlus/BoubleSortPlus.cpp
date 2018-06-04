#include <iostream>
using namespace std;


void numerosAleatorios(int  tamanho,long int  vet[]) {
	for (long int i = 0; i < tamanho; i++) {
		vet[i] = rand() % tamanho;
	}
}

void numerosSequenciais(int  tamanho,long int  vet[]) {
	for (long int i = 0; i < tamanho; i++) {
		vet[i] = i;
	}
}

void numerosDecrescente(int tamanho, long int vet[]){
	long int i = 0;
	while(tamanho !=0 ){
		vet[i] = tamanho;
		tamanho--;
		i++;
	}
}

void imprimeVetor(long int  qtd,  long int  vet[] ) {
	for (long int i = 0; i < qtd;  i++) {
		cout << vet[i] << " ";
	}
	cout << "." <<endl;
}

void imprimeVetorCincoPrimeiros(long int vet[]){
	for(long int i=0; i<5; i++){
		cout << vet[i] << ",";
	}
}

float bubble_sortPlus(long int vetor[], long int n) {
	clock_t start = clock();

	int aux, j, pass;

	for(pass = 0; pass < n-1; pass++){
		int troca = 1;

		for(j=0; j < n-pass-1; j++){
			
			if(vetor[j] > vetor[j+1]){
				aux = vetor[j];
				vetor[j] = vetor[j+1];
				vetor[j+1] = aux;
				troca = 0;
			}
			if(troca != 0){
				break;
			}
		}
	}

	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "QTD: "<< n << " TEMPO: " << seconds  << endl;
	return seconds;
}

void startBoubleSortAleatorio(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSortPlus" <<endl;
	cout << "Numeros aleatorios: " <<endl;
	cout << "=========================================" <<endl;

	long int cenario_1[5000];
	numerosAleatorios(5000, cenario_1);
	imprimeVetorCincoPrimeiros(cenario_1);
	bubble_sortPlus(cenario_1, 5000);


	long int cenario_2[50000];
	numerosAleatorios(50000, cenario_2);
	imprimeVetorCincoPrimeiros(cenario_2);	
	bubble_sortPlus(cenario_2, 50000);


	long int* cenario_3 = new long int [500000];
	numerosAleatorios(500000, cenario_3);
	imprimeVetorCincoPrimeiros(cenario_3);	
	bubble_sortPlus(cenario_3, 500000);

}

void startBoubleSortSequencial(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSort" <<endl;
	cout << "Vetor ja ordenado: " <<endl;
	cout << "=========================================" <<endl;
	

	long int cenario_1[5000];
	numerosSequenciais(5000, cenario_1);
	imprimeVetorCincoPrimeiros(cenario_1);	
	bubble_sortPlus(cenario_1, 5000);


	long int cenario_2[50000];
	imprimeVetorCincoPrimeiros(cenario_2);	
	numerosSequenciais(50000, cenario_2);
	bubble_sortPlus(cenario_2, 50000);


	long int* cenario_3 = new long int [500000];
	numerosSequenciais(500000, cenario_3);
	imprimeVetorCincoPrimeiros(cenario_3);	
	bubble_sortPlus(cenario_3, 500000);

}

void startBoubleSortDecrescente(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSort" <<endl;
	cout << "Vetor decrescente: " <<endl;
	cout << "=========================================" <<endl;
	

	long int cenario_1[5000];
	numerosDecrescente(5000, cenario_1);
	imprimeVetorCincoPrimeiros(cenario_1);	
	bubble_sortPlus(cenario_1, 5000);


	long int cenario_2[50000];
	numerosDecrescente(50000, cenario_2);
	imprimeVetorCincoPrimeiros(cenario_2);	
	bubble_sortPlus(cenario_2, 50000);


	long int* cenario_3 = new long int [500000];
	numerosDecrescente(500000, cenario_3);
	imprimeVetorCincoPrimeiros(cenario_3);	
	bubble_sortPlus(cenario_3, 500000);

}

int main()
{	
	srand(time(NULL));

	startBoubleSortAleatorio();
	startBoubleSortSequencial();
	startBoubleSortDecrescente();

}

