#include <stdio.h>
#include <stdlib.h>

int Alg(int* arr, int start, int end){
	int result=0;
	int i;
	for (i=start-1; i<end; i++){
		result += arr[i];
	}
	
	return result;
}

int main(void){
	int numOfArr, numOfQuery;
	int* arr;
	int* result;
	int i;
	int start, end;

	scanf("%d",&numOfArr);
	arr = (int*)malloc(sizeof(int)*numOfArr);
	
	for(i=0; i<numOfArr; i++){
		scanf("%d",&arr[i]);
	}

	scanf("%d",&numOfQuery);
	result = (int*)malloc(sizeof(int)*numOfQuery);

	for (i=0; i<numOfQuery; i++){
		scanf("%d%d",&start,&end);
		result[i] = Alg(arr,start,end);
	}

	for (i=0; i<numOfQuery; i++){
		printf("%d \n",result[i]);
	}


	return 0;
}