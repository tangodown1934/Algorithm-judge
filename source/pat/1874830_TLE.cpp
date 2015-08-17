#include<stdio.h>
int n,k;
int Arr[33];

void pat(int index){
	if(index==n) {
		int count=0;
		for(int i=0;i<n;i++){
			if(Arr[i]==1) 
				count++;
		}

		if(count==k){
			for(int i=0;i<n;i++){
				printf("%d",Arr[i]);
			}
			printf("\n");
		}
		
		return;
	}
	Arr[index]=1;
	pat(index+1);
	Arr[index]=0;
	pat(index+1);
}
int main(){

	scanf("%d %d",&n,&k);
	pat(0);
	return 0;
}