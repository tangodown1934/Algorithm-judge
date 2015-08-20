#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111

// 왼쪽 값과 오른쪽 값을 가지고 있어야하기 때문에 구조체로 구현
typedef struct elec
{
	int a;
	int b;
	int cnt;
}elec;


elec ele[SIZE];
int num[SIZE];

int main()
{
	int N;
	int A, B;

	int i, j;
	int max;
	elec temp;

	scanf("%d", &N);

	// INPUT
	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &ele[i].a, &ele[i].b);
	}

	// Bubble sort
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N - 1; j++)
		{
			if (ele[j].a > ele[j+1].a)
			{
				temp = ele[j];
				ele[j] = ele[j + 1];
				ele[j + 1] = temp;
			}
		}
	}

	// LIS 알고리즘 
	max = 0;
	for (i = 1; i <= N; i++)
	{
		ele[i].cnt = 1; // init
		for (j = 1; j < i; j++)
		{
			if (ele[j].b < ele[i].b && 1+ele[j].cnt > ele[i].cnt)
			{
				ele[i].cnt = ele[j].cnt + 1;
			}
		}

		if (max < ele[i].cnt)
			max = ele[i].cnt;
	}

	printf("%d\n", N-max);

	return 0;
}