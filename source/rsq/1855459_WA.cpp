#include <stdio.h>
//구간합->부분합
//20150708

int a[100000+1] = {0};
int sum_a[10000+1] = {0};

int func(int start, int end){
	if( start == 0 ){
		return sum_a[end];
	}
	return sum_a[end] - sum_a[start-1];
}

int main(){
	int n=0,q=0,start=0,end=0,i,j;
	int sum=0;
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
		printf("%d\n",func(start, end));
	}

	return 0;
}