#include <iostream>
#include <time.h>
#include <windows.h>

#define LENGTH 10
using namespace std;



void showVetor(int vetor[]){
    for(int i=0; i < LENGTH; i++){
        cout << vetor[i] << " ";
    }
}

void insertArray(int vetor[], int limit = 100){
    for(int i=0; i < LENGTH; i++){
        vetor[i] = rand() % limit;
    }
}

void insertSort(int vetor[]){
    int key = 0;
    for(int j = 1; j < LENGTH; j++ ){
        key = vetor[j];
        int i = j - 1;

        while(i >= 0 && vetor[i] > key){
                vetor[i+1] = vetor[i];
                i = i-1;
        }

        vetor[i+1] = key;
    }

    showVetor(vetor);
}

int main(){
    srand(time(NULL));
    int vetor[LENGTH];

    insertArray(vetor);

    insertSort(vetor);

}
