#include <iostream>
using namespace std;

//|0  |1  |2  |3 |4 |5 |6 |7
//|25 |57 |48 |37|12|92|86|33

void bolha(int vet[], int n){
    int i, j, aux;

    //   0    7 
    for(i=0; i<n-1; i++){

        //  0     7 
        for(j=0; j<n-1;j++){
            
            //     0         1
            if(vet[j] > vet[j+1]){
                aux = vet[j];
                vet[j] = vet[j+1];
                vet[j+1] = aux;

            }
        }
    }

}

int main (){
   int vet[8] = {25,57,48,37,12,92,86,33}; 

    bolha(vet,8);

    for(int i=0; i<8; i++){
        cout << vet[i] << ",";
    }
    cout << endl;

}