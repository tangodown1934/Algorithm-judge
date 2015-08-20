#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 33333

int num[SIZE] = { 0, };

int main()
{
	int i, j;
	int N;

	scanf("%d", &N);

	for (i = 2; i*i < SIZE; i++)
	{
		for (j = i * 2; j < SIZE; j += i)
		{
			num[j] = 1;
		}
	}

	if (!num[N]) printf("prime");
	else printf("not prime");
	printf("\n");
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}