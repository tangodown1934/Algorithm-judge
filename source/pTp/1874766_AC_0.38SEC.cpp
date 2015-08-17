#include<stdio.h>

void f(int n){
	if(n==1){printf("%d",n); return;}
	f(n-1);
	printf("%d",n);
	f(n-1);
}
int main(){

	int n;
	scanf("%d",&n);
	f(n);
	printf("\n");

	return 0;
}