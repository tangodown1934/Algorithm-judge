#include <stdio.h>

int main()
{
	int number[7];
	int min = 1000, max = 0;

	for (int i = 0; i < 7; i++)
		scanf("%d", &number[i]);

	for (int i = 0; i < 7; i++)
	{
		if (min>number[i]) min = number[i];
		if (max < number[i]) max = number[i];
	}

	printf("%d %d\n", max, min);

	return 0;
}