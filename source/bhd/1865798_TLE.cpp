#include <stdio.h>
#include <stdlib.h>

int Alg(int* cowHeight, int numOfCow){
	int i,j;
	int myHeght;
	int count =0;

	for (i=0; i<numOfCow-1; i++){
		for (j=i; j<numOfCow-1; j++){
			if (cowHeight[i] > cowHeight[j+1]){
				count++;
			}

			else
				break;
		}
	}

	return count;
}
int main(void){

	int numOfCow, result,i;
	int* cowHeight;

	scanf("%d",&numOfCow);
	cowHeight = (int*)malloc(sizeof(int)*numOfCow);
	for (i=0; i<numOfCow; i++){
		scanf("%d",&cowHeight[i]);
	}
	result = Alg(cowHeight,numOfCow);

	printf("%d \n",result);


	return 0;
}