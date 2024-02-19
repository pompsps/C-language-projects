#include <stdio.h>
#include <stdlib.h>
#define MAX_COUNT 10

int selectionSort(int[]);
void selectionSort2(int[]);

int main(void){
	int arr[10] = {10,7,2,3,5,4,1,6,8,9};
	
	printf("Example 1: ");
	selectionSort(arr);
	printf("\n");
	
	return 0;
}

int selectionSort(int arr[]){
	int i = 0, j = 0;
	int temp;
	int minimum;
	
	
	for(i = 0; i < MAX_COUNT; i++){
		
		minimum = i;
		
		for(j = i + 1; j < MAX_COUNT; j++){
			if(arr[j] < arr[minimum]){
				minimum = j;
			}
		}
		temp = arr[i];
		arr[i] = arr[minimum];
		arr[minimum] = temp;
	}
	
	for(i = 0; i < MAX_COUNT; i++)printf("%d ", arr[i]);
}
