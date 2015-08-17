#include <stdio.h>

int sum;
int minimum=999999;
int square[11111];

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int num1, num2;

	scanf("%d %d", &num1, &num2);

	for (int i = 1; i*i < 11111; i++)
	{
		square[i*i] = 1;
	}

	for (int i = num1; i <= num2; i++)
	{
		if (square[i] == 1){
			sum += i;
			minimum = min(minimum, i);
		}
	}

	if (!sum)
		printf("-1\n");
	else
		printf("%d\n%d\n", sum, minimum);


	return 0;
}