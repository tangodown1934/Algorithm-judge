#include <stdio.h>

int main()
{
	int number[7];
	int sum_1=0, sum_2=0, sum_3=0;

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &number[i]);
	}

	for (int i = 0; i < 7; i++)
	{
		if (number[i] >= 100) sum_3 += number[i];
		else if (number[i] >= 10) sum_2 += number[i];
		else sum_1 += number[i];
	}

	printf("%d %d %d\n", sum_1, sum_2, sum_3);

	return 0;
}