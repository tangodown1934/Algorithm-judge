#include <stdio.h>
#pragma warning(disable:4996)

#define SIZE 111111

int num[SIZE];

int ab(int n)
{
	if (n < 0)
		return n *= -1;
	else{
		return n;
	}
}

void q_sort(int arr[], int left, int right)
{
	int l, r;
	int pivot = arr[left];
	int temp;

	if (left < right)
	{
		l = left;
		r = right + 1;
		while (l <= r)
		{
			do{
				l++;
			} while (arr[l] < pivot);
			do{
				r--;
			} while (arr[r] > pivot);

			if (l < r)
			{
				temp = arr[l];
				arr[l] = arr[r];
				arr[r] = temp;
			}
			else{
				break;
			}
		}
		temp = arr[r];
		arr[r] = arr[left];
		arr[left] = temp;

		q_sort(arr, left, r - 1);
		q_sort(arr, r + 1, right);
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int N;
	int i;
	int s, e,s1,e1;
	int min;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr < nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &N);
		for (i = 0; i < N; i++)
		{
			scanf("%d", &num[i]);
		}

		q_sort(num, 0, N - 1);

		s = 0; e = N - 1;
		min = 2147483647;
		while (1)
		{
			if (ab(num[s] + num[e]) < min)
			{
				min = ab(num[s] + num[e]);
				s1 = s;
				e1 = e;
			}

			if (ab(num[s + 1] + num[e]) > ab(num[s] + num[e - 1]))
			{
				e--;
			}
			else{
				s++;
			}

			if (s == e) break;
		}
		printf("%d %d", num[s1], num[e1]);

		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}