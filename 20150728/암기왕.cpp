#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1100000

int a[SIZE];

// BST ÀÌÁøÅ½»öÆ®¸® 
// O(log2 n), ÃÖ¾Ç : O(n)
int bst(int arr[], int target, int first, int last)
{
	int half = (last - first) / 2 + first;

	if (first > last)
		return -1;

	if (target == arr[half])
		return half;
	else if (target < arr[half])
		return bst(arr, target, first, half - 1);
	else
		return bst(arr, target, half + 1, last);
}

void q_sort(int arr[], int left, int right)
{
	int l = left, r = right, temp;
	int pivot = arr[(left + right) / 2];

	do{
		while (pivot > arr[l]) l++;
		while (pivot < arr[r]) r--;

		if (l <= r)
		{
			temp = a[l];
			a[l] = a[r];
			a[r] = temp;
			l++; r--;
		}
	} while (l <= r);

	if(left<r) q_sort(arr, left, r);
	if(l<right) q_sort(arr, l, right);
}

int main()
{
	int n, nCount;
	int i;

	scanf("%d", &nCount);

	int a_count;
	int b_count;
	int target;

	for (n = 0; n < nCount; n++)
	{

		// input
		scanf("%d", &a_count);

		for (i = 0; i < a_count; i++)
		{
			scanf("%d", &a[i]);
		}

		q_sort(a, 0, a_count - 1); // quick sort

		scanf("%d", &b_count);
		for (i = 0; i < b_count; i++)
		{
			scanf("%d", &target);

			if (bst(a, target, 0, a_count - 1) != -1) // binary search 
				printf("1");
			else
				printf("0");

			printf("\n");
		}
	}
	return 0;
}