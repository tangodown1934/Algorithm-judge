
#include <stdio.h>

int n;

int func(int x){
	if (x <= 1) return 1;
	return func(x - 1) + func(x - 2);
}

int main(){
	scanf("%d", &n);
	printf("%d\n", func(n));
	return 0;
}