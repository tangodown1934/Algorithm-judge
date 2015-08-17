#include <stdio.h>

int main()
{
	int number[2];
	scanf("%d %d", &number[0], &number[1]);
	if (number[1] < number[0])
	{
		int temp;
		temp = number[0];
		number[0] = number[1];
		number[1] = temp;
	}
	for (int i = number[0]; i <= number[1]; i++)
		printf("%d ", i);
	printf("\n");


	return 0;
}