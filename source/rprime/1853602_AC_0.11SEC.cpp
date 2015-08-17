#include <stdio.h>

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

	if (GCD == 1)
		printf("yes\n");
	else printf("no\n");
	
	
}