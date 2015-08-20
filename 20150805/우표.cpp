#pragma warning(disable:4996)
#include <stdio.h>

#define INF 987654321
#define MAX 222
#define CMAX 2222222

int K, N;
int res;
int value[MAX];
int cache[CMAX];

void q_sort(int arr[], int left, int right)
{
	int l = left;
	int r = right;
	int temp;
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

int min(int a, int b)
{
	if (a > b)return b;
	return a;
}

int sol(int n)
{
	int i;

	if (n < 0)
		return 10;

	if (n == 0)
		return 0;

	int& ret = cache[n];
	if (ret != -1) return ret;

	ret = INF;
	for (i = 0; i < N; i++){
		ret = min(ret, 1 + sol(n - value[i])); // 그 다음값
	}

	return ret;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int i, j;


	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		// init
		for (i = 0; i < CMAX; i++)
			cache[i] = -1;

		printf("#testcase%d\n", itr + 1);

		scanf("%d %d", &K, &N);

		for (i = 0; i < N; i++)
		{
			scanf("%d", &value[i]);
		}

		// q_sort(value, 0, N-1); // sorting

		cache[value[0]] = 1;
		for (i = value[0] + 1; i < CMAX; i++)
		{
			sol(i);
			if (cache[i] > K) // K이상의 값이 캐시에 발견된다면
			{
				printf("%d\n", i - 1);
				break;
			}
		}
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}