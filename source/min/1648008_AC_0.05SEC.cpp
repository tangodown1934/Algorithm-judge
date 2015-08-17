#include <stdio.h>

int main()
{
	int number[7];
	int min = 1000;

	for (int i = 0; i < 7; i++)
		scanf("%d", &number[i]);

	for (int i = 0; i < 7; i++)
	if (min>number[i]) min = number[i];

	printf("%d\n", min);

	return 0;
}