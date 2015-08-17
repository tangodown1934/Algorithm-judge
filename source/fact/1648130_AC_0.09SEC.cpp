#include <stdio.h>

int main()
{
	int number, result=1;
	scanf("%d", &number);
	for (int i = 1; i <= number; i++)
	{
		result *= i;
	}
		
	printf("%d\n", result);
	return 0;
}