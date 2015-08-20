#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 333333

int N;
int num[SIZE];
int sort_grade[SIZE];
int grade[SIZE];

void q_sort(int arr[], int left, int right)
{
	int l, r;
	int temp;
	int pivot = arr[left];

	if (left < right)
	{
		l = left;
		r = right + 1;
		
		while (l <= r)
		{
			do{
				l++;
			} while (arr[l] > pivot);
			do{
				r--;
			} while (arr[r] < pivot);

			if (l < r)
			{
				temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
			}
		}

		temp = arr[left];
		arr[left] = arr[r];
		arr[r] = temp;

		q_sort(arr, left, r - 1);
		q_sort(arr, r + 1, right);
	}
}

void bubble_sort(int arr[], int n)
{
	int temp;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	int i;
	int cnt;

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &N);
		
		for (i = 0; i < SIZE; i++)
		{
			grade[i] = 0;
		}
		
		for (i = 0; i < N; i++)
		{
			scanf("%d", &num[i]);
			sort_grade[i] = num[i];
		}


		q_sort(sort_grade, 0, N-1);


		cnt = 0;
		for (i = 0; i < N; i++)
		{
			cnt++;
			if (grade[sort_grade[i]] == 0)
			{
				grade[sort_grade[i]] = cnt;
			}
		}

		for (i = 0; i < N; i++)
		{
			printf("%d\n", grade[num[i]]);
		}
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}