#include <stdio.h>
//n¹øÂ° ¼ö
//20150708


char str[1000000+1] = {0};

int func(int n){
	int res=0;
	res = str[n-1] - 48;
	return res;
}

int main(){
	int n=0;
	scanf("%s", str);
	scanf("%d", &n);
	printf("%d\n", func(n));



	return 0;
}