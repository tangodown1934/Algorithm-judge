#include <stdio.h>

int main()
{
	int n, min=1001;
	int arr[111];

	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
		if (min > arr[i]) min = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (arr[i] == min)
			printf("%d ", i+1);
	}
	printf("\n");

	return 0;
}