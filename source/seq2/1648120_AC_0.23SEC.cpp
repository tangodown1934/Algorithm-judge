#include <stdio.h>

int main()
{
	int number, result=0;
	scanf("%d", &number);
	for (int i = 1; i <= number; i++)
	{
		result += i;
		printf("1..%d %d\n", i, result);
	}
	return 0;
}