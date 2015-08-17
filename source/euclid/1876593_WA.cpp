#include <stdio.h>

int gcd(int x, int y)
{

	if (y == 0){

		return x;
	}

	return gcd(y,(x%y));


}

int main(void){

	int a, b;
	int result;
	scanf("%d %d", &a, &b);

	result = gcd(a, b);

	printf("%d %d", result,a*b/result);


	return 0;
}
