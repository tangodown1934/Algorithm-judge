
#include <stdio.h>

int func(int p, int q){
	if (q == 0) return p;
	return func(q, p % q);
}

int main(){

	int a, b;
	scanf("%d %d", &a, &b);
	int gcd = func(a, b);
	printf("%d %d\n", gcd, ((long long int)a*b) / gcd);
	return 0;
}