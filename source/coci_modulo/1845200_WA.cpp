#include <stdio.h>

int main()
{
	int n, num=0;
	int arr[11], result[11];

	for (int i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		result[i] = arr[i] % 42;
	}

	for (int i = 0; i < 42; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == result[j])
				num++;
		}
			
	}

	printf("%d\n", num);
	return 0;
}