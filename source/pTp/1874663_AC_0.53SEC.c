#include <stdio.h>

void Alg(int height){

	if (height ==0){
		return;
	}
	else{
		Alg(height-1);
		printf("%d",height);
		Alg(height-1);
	}
}

int main(void){

	int height;
	int result;
	int i;

	scanf("%d",&height);
	Alg(height);
	printf("\n");

	return 0;
}