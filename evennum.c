#include <stdio.h>
#include <stdlib.h>

int count = 0;
int numCount = 1;
int start = 1, end = 5;

void input(int*, int, int);
void printThis(int*, int);

int main(void){
	int myArray[5] = {0};
	
	printf("Enter five numbers and I will print all even numbers: \n");
	input(myArray, start, end);

	printf("Even numbers Detected: ");
	printThis(myArray, start);
	
	return 0;
}

void input(int *myArray, int start, int end){
	int temp;	
	
	if(start<=end){
		printf("[%d] ", numCount);
		numCount++;
		scanf("%d", &temp);
		if(temp % 2 == 0){
			myArray[count] = temp;
			count++;
			input(myArray, ++start, end);
		}else{
			input(myArray, start, end);
		}
	}
}

void printThis(int *myArray, int start){
	if(start<=count){
		printf("%d ", myArray[start - 1]);
		printThis(myArray, ++start);
	}
}


