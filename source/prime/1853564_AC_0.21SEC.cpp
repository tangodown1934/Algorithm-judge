#include <stdio.h>

#define SIZE 33333

bool isPrime[SIZE];

int main()
{
	int num;
	scanf("%d", &num);

	for (int i = 0; i < SIZE; i++)
		isPrime[i] = true;

	for (int i = 2; i < SIZE; i++)
	{
		if (isPrime[i])
		{
			for (int j = i*2; j < SIZE; j+=i)
				isPrime[j] = false;
		}
	}

	if (isPrime[num])
		printf("prime\n");
	else
		printf("not prime\n");
}