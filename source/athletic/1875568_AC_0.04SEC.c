#include <stdio.h>

#define MAX 10

int count = 0;
void Alg(char arr[MAX],int numOfWins, int idx, int winCount, int loseCount){
	int i;
	int tempCount = 0;

	if ((idx>=numOfWins) && (winCount == numOfWins) && (loseCount < numOfWins)){
		count++;
		for(i=0; i<idx; i++)
			printf("%c",arr[i]);

		printf("\n");
		return;
	}

	if (loseCount >= numOfWins){
		return ;
	}

	if (idx == 0){
		arr[idx] = 'o';
		Alg(arr,numOfWins,idx+1,winCount+1,loseCount);
		arr[idx] = 'x';
		Alg(arr,numOfWins,idx+1, winCount,loseCount+1);
	}

	else{
		for (i=0; i<idx; i++){
			if (arr[i] == 'x'){
				tempCount++;
			}
		}

		if (tempCount == numOfWins-1){
			arr[idx] = 'o';
			Alg(arr,numOfWins,idx+1,winCount+1,loseCount);
		}
		else{
			arr[idx] = 'o';
			Alg(arr,numOfWins,idx+1,winCount+1,loseCount);
			arr[idx] = 'x';
			Alg(arr,numOfWins,idx+1, winCount,loseCount+1);
		}
	}
}

int main(void){
	
	int numOfWins;
	char arr[MAX];

	scanf("%d",&numOfWins);
	Alg(arr,numOfWins,0,0,0);
	printf("total %d case(s) \n",count);
	count=0;

	return 0;
}