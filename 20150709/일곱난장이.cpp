#pragma warning(disable:4996)
#include <stdio.h>

#define MAX 11
#define INF 987654321

int num[MAX];

void q_sort(int arr[], int left, int right)
{
	int temp;
	int l = left;
	int r = right;
	int pivot = arr[(left + right) / 2];
	
	do{
		while (pivot > arr[l]) l++;
		while (pivot < arr[r]) r--;

		if (l <= r)
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++; r--;
		}
	} while (l < r);
	if (left < r) q_sort(arr, left, r);
	if (right > l) q_sort(arr, l, right);
}

int main()
{
	int sum;
	int i,j,k;
	int non1, non2;

	sum = 0;
	for (i = 0; i < 9; i++)
	{
		scanf("%d", &num[i]);
		sum += num[i];
	}

	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (i!=j && num[i] + num[j] == sum - 100)
			{
				num[j] = num[i] = INF;
				break;
			}
		}
	}
	q_sort(num, 0, 8);

	for (i = 0; i < 7; i++)
	{
		printf("%d\n", num[i]);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}