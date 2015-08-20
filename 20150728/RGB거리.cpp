#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1111

int home[SIZE][4];

int N;
int min;

// 인덱스, 합계, 이전값을 기억하고 있어야함
void sol(int idx, int sum, int pre)
{
	if (idx == N)
	{
		//printf("sum : %d\n", sum);
		if (min > sum)
			min = sum;

		return;
	}

	for (int i = 0; i < 3; i++)
	{
		if (i != pre) // 이웃집 색상과 같으면 안됨
		{
			//printf("idx : %d / i: %d, pre : %d, number : %d\n", idx, i, pre, home[idx][i]);

			sum += home[idx][i];  
			sol(idx + 1, sum, i); // 이웃집을 칠해줌 
			sum -= home[idx][i];
		}
	}
}

int main()
{
	int i, j;

	scanf("%d", &N);

	// input
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &home[i][j]);
			min += home[i][j];
		}
	}

	sol(0, 0, -1); 
	printf("%d\n", min);

	return 0;
}