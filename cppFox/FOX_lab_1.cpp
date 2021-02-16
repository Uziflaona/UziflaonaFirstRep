#include <iostream>
#include <iomanip>
#include <time.h>
#include <stdlib.h>

int pSumOfMult(int *array, int ){
	
	return (0);
}

int nSumOfMult(int array[], int index){
	int sum;
	for (int i=0; i<index/2; i++){
		sum += array[i]*array[(index-1)-i];	
	}
	return (sum);
}

using namespace std;

int main(){
	int L[20][16];
	srand(time(NULL));
	for (int i=0; i<20; i++){ // Filling an array with random values
		for (int j=0; j<16; j++){
			L[i][j] = rand() % 10;
			cout << setw(4) << L[i][j];
		}
		cout << endl;
	}

	for (int i=0; i<20; i++){
		cout << nSumOfMult(L[i], 16) << endl;
	}
}


