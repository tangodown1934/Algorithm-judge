#include <stdio.h>

int main()
{
	int number;

	scanf("%d", &number);

	while (number != 1)
	{
		printf("%d ", number);
		if (number % 2 == 1)
			number = number * 3 + 1;
		else
			number /= 2;
	}

	printf("%d \n", number);

	return 0;
}