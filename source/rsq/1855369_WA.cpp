#include <stdio.h>
#include <string.h>
//구간합->부분합
//20150708

long a[100000+1] = {0};
long sum_a[10000+1];

long func(int start, int end){
	int i=0;
	long sum = 0;
	if( start == 0 ){
		return sum_a[end];
	}
	sum = sum_a[end] - sum_a[start-1];
	/*
	for( i=start; i<= end; i++){
		sum += a[i];
	}
	*/
	return sum;
}

int main(){
	int n=0,q=0,start=0,end=0,i,j;
	long sum=0;
	memset(sum_a,0,sizeof(sum_a));
	scanf("%d", &n);
	for(i=0;i<n;i++){
		scanf("%d", &a[i]);
		sum += a[i];
		sum_a[i] = sum;
	}
	scanf("%d", &q);
	for(i=0;i<q;i++){
		scanf("%d %d", &start, &end);
		start--,end--;
		printf("%lld\n",func(start, end));
	}

	return 0;
}