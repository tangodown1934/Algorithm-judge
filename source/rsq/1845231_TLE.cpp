#include <stdio.h>

int arr[111111], start[111111], end[111111];

int main()
{
	int n, q;
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &start[i], &end[i]);
	}


	for (int i = 0; i < q; i++)
	{
		sum = 0;
		for (int j = start[i] - 1; j <= end[i] - 1; j++)
			sum += arr[j];
		printf("%d\n", sum);
	}

	return 0;
}