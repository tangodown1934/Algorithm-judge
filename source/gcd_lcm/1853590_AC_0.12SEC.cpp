#include <stdio.h>

int min(int a, int b)
{
	if (a < b)
		return a;
	return b;
}

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int num1, num2, GCD;
	scanf("%d %d", &num1, &num2);

	GCD = gcd(num1, num2);

	printf("%d %d\n", GCD, num1*num2/GCD);
	
}