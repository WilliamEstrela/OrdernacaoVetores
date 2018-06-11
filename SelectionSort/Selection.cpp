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

float selection(long int vetor[], long int n) {
	long int comparacoes=0;
	long int alteracoes=0;
	clock_t start = clock();

	int i, j, aux, Max;
	
	for(i=0;i<n -1;i++){
		Max = i;

		for (j = i + 1 ; j < n; j++){
        comparacoes++;
            if ( vetor[j] > vetor[Max]){
                    Max = j;                  
            } 
        }
        aux = vetor[Max];
        vetor[Max] = vetor[i];
        vetor[i] = aux;
        alteracoes++;
	}

	clock_t end = clock();
	float seconds = (float)(end - start) / CLOCKS_PER_SEC;
	cout << "QTD: "<< n << " TEMPO: " << seconds << " Comparacoes: "<< comparacoes << " Alteracoes: " << alteracoes << endl;
	return seconds;
}

void startSelectionAleatorio(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSortPlus" <<endl;
	cout << "Numeros aleatorios: " <<endl;
	cout << "=========================================" <<endl;

	long int cenario_1[5000];
	numerosAleatorios(5000, cenario_1);
	imprimeVetorCincoPrimeiros(cenario_1);
	selection(cenario_1, 5000);


	long int cenario_2[50000];
	numerosAleatorios(50000, cenario_2);
	imprimeVetorCincoPrimeiros(cenario_2);	
	selection(cenario_2, 50000);


	long int* cenario_3 = new long int [500000];
	numerosAleatorios(500000, cenario_3);
	imprimeVetorCincoPrimeiros(cenario_3);	
	selection(cenario_3, 500000);

}

void startSelectionOrdenado(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSort" <<endl;
	cout << "Vetor ja ordenado: " <<endl;
	cout << "=========================================" <<endl;
	

	long int cenario_1[5000];
	numerosSequenciais(5000, cenario_1);
	imprimeVetorCincoPrimeiros(cenario_1);	
	selection(cenario_1, 5000);


	long int cenario_2[50000];
	numerosSequenciais(50000, cenario_2);
	selection(cenario_2, 50000);
	imprimeVetorCincoPrimeiros(cenario_2);	

	long int* cenario_3 = new long int [500000];
	numerosSequenciais(500000, cenario_3);
	imprimeVetorCincoPrimeiros(cenario_3);	
	selection(cenario_3, 500000);

}

void startSelectionDecrescente(){
	cout << "=========================================" <<endl;
	cout << "Iniciando testes de desenpenho BoubleSort" <<endl;
	cout << "Vetor decrescente: " <<endl;
	cout << "=========================================" <<endl;
	

	long int cenario_1[5000];
	numerosDecrescente(5000, cenario_1);
	selection(cenario_1, 5000);
	imprimeVetorCincoPrimeiros(cenario_1);	


	long int cenario_2[50000];
	numerosDecrescente(50000, cenario_2);
	selection(cenario_2, 50000);
	imprimeVetorCincoPrimeiros(cenario_2);	
	


	long int* cenario_3 = new long int [500000];
	numerosDecrescente(500000, cenario_3);
	selection(cenario_3, 500000);
	imprimeVetorCincoPrimeiros(cenario_3);	
	

}

int main()
{	
	srand(time(NULL));

	startSelectionAleatorio();
	startSelectionOrdenado();
	startSelectionDecrescente();

}

