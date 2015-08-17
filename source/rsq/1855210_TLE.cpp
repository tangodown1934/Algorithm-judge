#include <stdio.h>
//±¸°£ÇÕ
//20150708

int a[100000+1] = {0};

int func(int start, int end){
	int i=0, sum = 0;
	for( i=start; i<= end; i++){
		sum += a[i];
	}
	return sum;
}

int main(){
	int n=0,q=0,start=0,end=0,i,j;
	
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
	}
	scanf("%d", &q);
	for(i=0;i<q;i++){
		scanf("%d %d", &start, &end);
		start--,end--;
		printf("%d\n",func(start, end));
	}

	return 0;
}