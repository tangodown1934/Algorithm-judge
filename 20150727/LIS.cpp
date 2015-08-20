#include <stdio.h>
#pragma warning(disable:4996)

#define SIZE 555

char num[SIZE];
int cache[SIZE];
int N;
int max;

int lis(int idx)
{
	int temp;
	int& ret = cache[idx];
	if (ret != -1) return ret;

	ret = 1;
	for (int next = idx + 1; next < N; next++)
	{
		if (num[idx] < num[next])
		{
			temp = 1 + lis(next);
			printf("%d,%d = %d\n", idx, next, temp);
			if (temp > ret)
				ret = temp;
		}
	}
	return ret;
}

int main()
{
	int n, nCount;

	scanf("%d\n", &nCount);

	for (n = 0; n<nCount; n++)
	{
		int i;
		int temp;

		scanf("%d", &N);

		// Init
		for (i = 0; i < N; i++)
		{
			cache[i] = -1;
		}

		for (i = 0; i < N; i++)
		{
			scanf("%d", &num[i]);
		}
		
		max = -1;
		for (i = 0; i < N; i++)
		{
			temp = lis(i);
			if(max < temp)
				max = temp;
		}
		printf("%d\n", max);
	}

	return 0;
}