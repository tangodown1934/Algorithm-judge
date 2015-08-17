#include <stdio.h>

#define DIV_NUM 42
#define ARR_SIZE 10

int Alg(int* arr){
	int count;
	int i,j;

	for(i=0; i<ARR_SIZE; i++){
		arr[i] = arr[i]%DIV_NUM;
	}

	for(i=0; i<ARR_SIZE-1; i++){
		for (j=1; j<ARR_SIZE; j++){
			if (arr[i] == arr[j]){
				arr[j] = -1;
			}
		}
	}

	for (i=0; i<ARR_SIZE; i++){
		if (arr[i] != -1){
			count++;
		}
	}

	return  count;

}
int main(void){
	int arr[ARR_SIZE];
	int i;
	int flag;

	for(i=0; i<ARR_SIZE; i++){
		scanf("%d",&arr[i]);
	}

	flag = Alg(arr);
	printf("%d \n",arr);

	return 0;
}