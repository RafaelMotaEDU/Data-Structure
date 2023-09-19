#include <iostream>
#include <stdlib.h>
#include <time.h>

#define LENGTH 10
using namespace std;

void insert(int array[], int limit = 50){
    for(int i=0; i < LENGTH; i++)
        array[i] = rand() % limit;
}

void show(int array[]){
    for(int i=0; i < LENGTH; i++)
        cout<< array[i] << " ";
}

bool search(int array[], int length, int value){
    if(length < 0) return false;
    if(array[length - 1] == value) return true;

    return search(array, length - 1, value);
}

int main(){
    int array[LENGTH];
    insert(array);

    show(array);

    cout << endl;
    cout << search(array, LENGTH, 14);
}
