#include <stdio.h>
#include <stdlib.h>

int main(){
	int arr[9] = {5,4,26,32,1,5,3,2,8};
	int x = 0, y = 0, j = 0;
	int temp;	
	int i = 0;
	int count = 0;

	
	for(x = 0; x < 4 - 1; x++){
		
		for(y = 0; y < 4 - i - 1; y++){
			if(arr[y] > arr[y + 1]){
				temp = arr[y];
				arr[y] = arr[y + 1];
				arr[y + 1] = temp;
			}
		}
	}

	while(i < sizeof(arr)/sizeof(int)){
	 	printf("%d ", arr[i]);
		i++;	
	}
}

/*
{5,4,26,32,1,5,3,2,8}

bubble

4,5,26,1,5,3,2,8,32
4,5,1,5,3,2,8,26,32
4,1,5,3,2,5,8,26,32
1,4,3,2,5,5,8,26,32

insertion

[5] - index 0
4,|5,26,32,1,5,3,2,8
[5] - index 0 + 1
4,5,|26,32,1,5,3,2,8
[26] index 1 + 1
4,5,26,|32,1,5,3,2,8

*/

