#include <stdio.h>

int arr[111111], start[111111], end[111111];
int ans[111111];
int psum[111111];

int main()
{
	int n, q;
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	psum[0] = arr[0];

	scanf("%d", &q);
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d", &start[i], &end[i]);
	}

	for (int i = 1; i < n; i++)
	{
		psum[i] = psum[i-1] + arr[i];
	}

	for (int i = 0; i < q; i++)
	{
			printf("%d\n", psum[end[i]-1] - psum[start[i]-2]);
	}

	return 0;
}