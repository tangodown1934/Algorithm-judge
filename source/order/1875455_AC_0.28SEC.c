#include <stdio.h>

#define MAX 13
int count = 0;

void Swap(char* ch1, char* ch2){
	char temp;
	temp = *ch1;
	*ch1 = *ch2;
	*ch2 = temp;
}

void Alg_PE(char set[MAX],char arr[MAX] ,int N, int R, int P, int idx){
	int i,j;
	int flag=0;
	if ((idx == R)){
		if (++count == P){
			for (i=0; i<R; i++){
				printf("%c",arr[i]);
			}
			printf("\n");
		}
		return ;
	}

	if (count == P)
		return ;

	for (i=0; i<N; i++){
		for (j=0; j<idx; j++){
			if (arr[j] == set[i]){
				flag = 1;
			}
		}

		if (flag == 0){
			arr[idx] = set[i];
			Alg_PE(set,arr,N,R,P,idx+1);
		}
		flag = 0;
	}
}

void Alg_CO(char set[MAX],char arr[MAX],int N, int R, int Q, int idx){
	int i,j;
	int flag=0;
	if ((idx == R)){
		if (++count == Q){
			for (i=0; i<R; i++){
				printf("%c",arr[i]);
			}
			printf("\n");
		}
		return ;
	}

	if (count == Q)
		return ;

	if (idx == 0){
		for (i=0; i<N; i++){
			arr[idx] = set[i];
			Alg_CO(set,arr,N,R,Q,idx+1);
		}
	}

	else{
		for (i=idx; i<N; i++){

			if ((arr[idx-1] < set[i])){
				arr[idx] = set[i];
				Alg_CO(set,arr,N,R,Q,idx+1);
			}
		}
	}
}

int main()
{


	int N,R,P,Q;
	char set[MAX] = {'A','B','C','D','E','F','G','H','I','J','K','L'};
	char arr[MAX];



		scanf("%d%d",&N,&R);
		scanf("%d%d",&P,&Q);

		Alg_PE(set,arr,N,R,P,0);		
		count=0;
		Alg_CO(set,arr,N,R,Q,0);
		count =0;


	return 0;	
}