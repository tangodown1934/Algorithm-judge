#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1111
#define RGB_SIZE 3

int home[SIZE][4];
int dp[SIZE][4];

int N;

int min(int a, int b)
{
	if (a < b)
		return a;
	else
		return b;
}

int main()
{
	int i, j;
	int minValue;

	scanf("%d", &N);

	// input
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= RGB_SIZE; j++)
		{
			scanf("%d", &home[i][j]);
		}
	}

	// init 첫줄의 최소비용은 자기 자신의 집에대한 비용임
	dp[1][1] = home[1][1];
	dp[1][2] = home[1][2];
	dp[1][3] = home[1][3];

	for (i = 2; i <= N; i++)
	{
		dp[i][1] = min(dp[i - 1][2] + home[i][1], dp[i - 1][3] + home[i][1]); // RED
		dp[i][2] = min(dp[i - 1][1] + home[i][2], dp[i - 1][3] + home[i][2]); // GREEN
		dp[i][3] = min(dp[i - 1][1] + home[i][3], dp[i - 1][2] + home[i][3]); // BLUE
	}

	
	// 마지막 줄 RGB 비용 중 최소값
	minValue = dp[N][1];
	for (i = 2; i <= RGB_SIZE; i++)
	{
		if (minValue > dp[N][i])
			minValue = dp[N][i];
	}

	printf("%d\n", minValue);
	return 0;
}