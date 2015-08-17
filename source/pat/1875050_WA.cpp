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
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		scanf("%d %d",&n,&k);
		printf("#testcase%d\n",itr+1);

		if(k==n){
			for(int i=0;i<n;i++){
				printf("1");
			}
			printf("\n");
		}else if(k==1){
			for(int i=0;i<n;i++){
				Arr[i]=1;
				for(int j=0;j<n;j++){
					printf("%d",Arr[j]);
				}
				Arr[i]=0;
				printf("\n");
			}
			printf("\n");
		}else{
			pat(0);
		}
	}
	return 0;
}