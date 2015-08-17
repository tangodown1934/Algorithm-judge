#include <stdio.h>

#define MAX_LEN 50

int main(void){

	char inArr[MAX_LEN];
	char temp;
	int leftIdx[MAX_LEN];
	int rightIdx[MAX_LEN];
	int length=0;
	int i=0,j=0,k=0,l=0;

	scanf("%s",inArr);
	
	for (i=0; i<MAX_LEN; i++){
		if (inArr[i] == '\0'){
			break;
		}

		length++;
	}

	for (i=0; i<length; i++){
		if (inArr[i] == '(')
			leftIdx[j++] = i;

		else if(inArr[i] == ')'){
			rightIdx[k++] = i;
		}
	}

	if (j==k){
		for (i=0,l=k-1;i<j;i++,l--){
			printf("%d %d \n",leftIdx[l],rightIdx[i]);
		}
	}

	else
		printf("not match \n");	

	return 0;
}