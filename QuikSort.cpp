#include<iostream>

using namespace std;

void swap(int *a, int *b){
	
	int t = *a;
	*a = *b;
	*b = t;
}

// function to print array

void printArray(int array[], int size){

	for (int i=0; i<size; i++)
		cout << array[i] << " ";
	cout<< endl;
}

// function to rearrange array **find partion point**

int partition(int array[], int low, int high){
	
	// select the rightmost elemet as pivot 
	int pivot = array[high];
	// pointer for greater element 
	int i = low - 1;


	// traverse each element of the array
	// compare them with the pivot 
	for (int j=low; j<high; j++){
		if(array[j]<=pivot){
			// if the element is smaller than pivot is found
			//  swap it with the greater element pointed by i
			i++;
			// swap element at i with the element at j
			swap(&array[i], &array[j]);

			}
}
		// swap pivot with greater element at i
		swap(&array[i+1], &array[high]);


	// return the partition point
	return (i+1);
}


void quickSort(int array[], int low, int high){

	if (low < high){
	
		int pi = partition(array, low, high);


		// recursive call on the Left of the pivot 
		quickSort(array, low, pi-1);
		quickSort(array, pi+1,high);
	}
}


int main(int argc, char** argv){
	
	int data[] = {1, 5, 6, 3, 2, 9, 10};
	int n = sizeof(data)/sizeof(data[0]);
	cout << "unsorted array....!" << endl;
	printArray(data, n);
	

	// QuickSort launch..
	quickSort(data, 0, n-1);


	// sorted array
	printArray(data,n);
}
