#include <stdio.h>

int main()
{
	int number[7], min=100, result=0;

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &number[i]);
		if (number[i] % 2 == 1)
		{
			if (min > number[i]) min = number[i];
			result += number[i];
		}
	}
	printf("%d\n%d\n", result, min);
	return 0;
}