#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

int* Alg(int arr[], int arrSize){
	int* arrIdx = (int*)malloc(sizeof(int)*arrSize);
	
	int i,minValue = 1000;
	
	for(i=0; i<arrSize; i++){
		if (minValue> arr[i]){
			minValue = arr[i];
		}
	}

	for (i=0; i<arrSize; i++){
		if (arr[i] == minValue){
			arrIdx[i] = TRUE;
		}

		else
			arrIdx[i] = FALSE;
	}

	return arrIdx;

}
int main(void){
	int* arr;
	int * arrIdx;
	int arrSize, i;

	scanf("%d",&arrSize);
	arr = (int*)malloc(sizeof(int)*arrSize);
	arrIdx = (int*)malloc(sizeof(int)*arrSize);

	for (i=0; i<arrSize; i++){
		scanf("%d",&arr[i]);
	}

	arrIdx = Alg(arr, arrSize);

	for(i=0; i<arrSize; i++){
		if (arrIdx[i] == TRUE)
			printf("%d ",i+1);
	}
	printf("\n");
	
	return 0;
}