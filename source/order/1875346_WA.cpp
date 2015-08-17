#include<stdio.h>
int n,r,p,q;
int Arr[13];
int Brr[13];
int count;
int count2;

void order2(int index){
	if(index==r){
		count2++;
		if(count2==q){
			for(int i=0;i<r;i++){
				printf("%c",Brr[i]+65);
			}
			printf("\n");
		}
		return;
	}

	for(int i=index;i<n;i++){
		if(Brr[0]==0){
			Brr[index]=i;
			order2(index+1);
		}else if(Brr[index-1]<i){
			Brr[index]=i;
			order2(index+1);
		}
	}
}

void order(int index){

	if(index==r){
		count++;
		if(count==p+1){
			for(int i=0;i<r;i++){
				printf("%c",Arr[i]+65);
			}
			printf("\n");
		}
		return;
	}
	for(int i=0;i<n;i++){
		if(Arr[0]==0){
			Arr[index]=i;
			order(index+1);
		}else if(Arr[index-1]!=i){
			Arr[index]=i;
			order(index+1);
		}
	}
}

int main(){
	/*int itr;
	int nCount;		

	scanf("%d", &nCount);	

	for(itr=0; itr<nCount; itr++)
	{*/
	
		scanf("%d %d",&n,&r);
		scanf("%d %d",&p,&q);
		//printf("#testcase%d\n",itr+1);

		order(0);

		order2(0);

	//}
	return 0;
}
