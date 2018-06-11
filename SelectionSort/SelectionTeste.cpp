#include<stdio.h>
#include <iostream>
using namespace std;

void numerosAleatorios(int  tamanho,long int  vet[]) {
	for (long int i = 0; i < tamanho; i++) {
		vet[i] = rand() % tamanho;
	}
}


void selcDireta(long int v[],long int n){
	
	int i, j, aux, Max;
	
	for(i=0;i<n -1;i++){
		Max = i;
		for (j = i + 1 ; j < n; j++){
     		 if ( v[j] > v[Max]) {
                 Max = j;
   				 aux = v[Max];
  				 v[Max] = v[i];
   				 v[i] = aux;  
              }

        }

	}
}

int main(){
	long int v[50000];

	
    numerosAleatorios(50000, v);

	selcDireta(v, 50000);
	
	printf("Selecao Direta\n");
	
	// for(long int i=0; i<50000; i++){
	// 	cout << "N: " << v[i];
	// }
	
	printf("Vetor Ordenado!!\n");	

}