#include <stdio.h>

int N, cnt;
long long int arr[88888];

int main()
{
	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &arr[i]);
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = i+1; j < N; j++)
		{
			if (arr[i] < arr[j]) break;
			cnt++;
		}
	}

	printf("%d\n", cnt);

	return 0;
}