#include <stdio.h>

int main()
{
	int number[7];
	int max=0;

	for (int i = 0; i < 7; i++)
		scanf("%d", &number[i]);

	for (int i = 0; i < 7; i++)
	if (max<number[i]) max = number[i];

	printf("%d\n", max);

	return 0;
}