#include <stdio.h>

#pragma warning(disable:4996)

#define SIZE 111

int cache[SIZE];
int N;

int tiling(int width)
{
	if (width <= 1)
		return 1;

	int& ret = cache[width];
	if (ret != -1) return ret;

	return ret = (tiling(width - 1) + tiling(width - 2)) % 1000000007;
}

int main()
{
	int n, nCount;

	scanf("%d", &nCount);

	for (n = 0; n < nCount; n++)
	{
		scanf("%d", &N);

		for (int i = 0; i < SIZE; i++)
		{
			cache[i] = -1;
		}

		printf("%d\n", tiling(N));
	}
}