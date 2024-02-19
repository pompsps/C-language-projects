#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 10

void insertionSort(int[]);

int main(void){
	int arr[10] = {5,4,26,32,1,5,3,2,8,10};
	int i = 0;
	
	insertionSort(arr);
	
	for(i = 0; i < MAX_COUNT; i++){
		printf("%d ", arr[i]);		
	}
}

void insertionSort(int arr[]){ 
	int i = 0, j = 0;
	int temp;

	for(i = 1; i < MAX_COUNT; i++){

		temp = arr[i];
		j = i - 1;
		

		while(j >= 0 && arr[j] > temp){
			arr[j + 1] = arr[j];
			j--;
			
		}
		
		arr[j + 1] = temp;
	}
}

