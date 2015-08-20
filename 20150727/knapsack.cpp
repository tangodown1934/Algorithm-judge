#include <stdio.h>
#include <algorithm>

using namespace std;

#pragma warning(disable:4996)
#define SIZE 111
#define LEN 11111

int N;
int value[SIZE];
int weight[SIZE];
int cache[SIZE][LEN] = { -1 };
int maxWeight;

const int INF = 987654321;

int sol(int idx, int leftweight)
{
	if (leftweight < 0)
		return -INF;

	if (idx == N+1)
		return 0;

	int& ret = cache[idx][leftweight];
	if (ret != -1) return ret;

	ret = 0;
	ret = max(ret, value[idx] + sol(idx + 1, leftweight - weight[idx])); // 1 

	ret = max(ret, sol(idx + 1, leftweight)); // 0

	return ret;
}

int main()
{
	int i, j;

	scanf("%d", &maxWeight);
	scanf("%d", &N);

	// init
	for (i = 0; i < SIZE; i++)
	{
		for (j = 0; j < LEN; j++)
		{
			cache[i][j] = -1;
		}
	}

	for (i = 0; i < N; i++)
	{
		scanf("%d %d", &weight[i], &value[i]);
	}

	printf("%d\n", sol(0, maxWeight));

	return 0;
}