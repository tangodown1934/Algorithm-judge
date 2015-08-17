#include <stdio.h>

int main()
{
	int number;
	int result=0;

	scanf("%d", &number);

	for (int i = 1; i <= number; i++)
	{
		printf("%d", i);
		result += i;
		if (number == i) break;
		printf("+");
	}
		
	printf("=%d \n", result);

	return 0;
}