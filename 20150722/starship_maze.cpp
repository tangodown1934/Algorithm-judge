#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 555555

int room[111111][111111];
int visited[SIZE];
int N, M;

void dfs(int n)
{
	visited[n] = 1;
	printf("%d\n", n);

	for (int i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && room[n][i] == 1)
			dfs(i);
	}
}

int main()
{
	int i, j;
	int a, b;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N;i++)
	{
		visited[i] = 0;
		for (j = 1; j <= M; j++)
		{
			room[i][j] = 0;
		}
	}

	for (i = 1; i <= M; i++)
	{
		scanf("%d  %d", &a, &b);
		room[a][b] = room[b][a] = 1;
	}

	dfs(1);
}