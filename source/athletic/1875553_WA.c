#include <stdio.h>

#define MAX 10

int count = 0;
void Alg(char arr[MAX],int numOfWins, int idx, int winCount){
	int i;
	int tempCount = 0;

	if ((idx>=3) && (winCount == numOfWins)){
		count++;
		for(i=0; i<idx; i++)
			printf("%c",arr[i]);

		printf("\n");
		return;
	}

	if (idx == 0){
		arr[idx] = 'o';
		Alg(arr,numOfWins,idx+1,winCount+1);
		arr[idx] = 'x';
		Alg(arr,numOfWins,idx+1, winCount);
	}

	else{
		for (i=0; i<idx; i++){
			if (arr[i] == 'x'){
				tempCount++;
			}
		}

		if (tempCount == 2){
			arr[idx] = 'o';
			Alg(arr,numOfWins,idx+1,winCount+1);
		}
		else{
			arr[idx] = 'o';
			Alg(arr,numOfWins,idx+1,winCount+1);
			arr[idx] = 'x';
			Alg(arr,numOfWins,idx+1, winCount);
		}
	}
	


}

int main(void){
	
	int numOfWins;
	char arr[MAX];

	scanf("%d",&numOfWins);
	Alg(arr,numOfWins,0,0);
	printf("total %d case(s) \n",count);
	count=0;

	return 0;
}