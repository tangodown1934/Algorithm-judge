#include <stdio.h>

int N, M;
int matrix[100][100];
int min = 999999;

int delX[4] = { 0, 0, 1, -1 };
int delY[4] = { 1, -1, 0, 0 };

void DFS(int x, int y, int cnt)
{
	if (x == 1 && y == M)
	{
		if (min > cnt) min = cnt;
	}
	matrix[x][y] = 1;

	for (int i = 0; i < 4; i++)
	{
		if (matrix[x + delX[i]][y + delY[i]] == 0)
		{
			DFS(x + delX[i], y + delY[i], cnt + 1);
		}
	}

	matrix[x][y] = 0;
}

int main()
{
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < M + 2; j++)
		{
			matrix[i][j] = 1;
		}
	}

	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < M + 1; j++)
		{
			scanf("%1d", &matrix[i][j]);
		}
	}

	DFS(N, 1, 1);

	if (min == 999999) printf("-1\n");
	else printf("%d\n", min);


	return 0;
}