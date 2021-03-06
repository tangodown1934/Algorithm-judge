#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111

int maze[SIZE][SIZE];
int visited[SIZE][SIZE];
int N, M;

int res;
int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };
const int INF = 987654321;

void print(){
	printf("\n");
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= M; j++)
		{
			printf("%d", visited[i][j]);
		}
		printf("\n");
	}
}

void dfs(int x, int y, int step)
{
	int mX, mY;

	visited[x][y] = step;
	if (x == N && y == M){
		if (res > step)
			res = step;
	}
	else{
		for (int i = 0; i < 4; i++)
		{
			mX = x + pX[i]; mY = y + pY[i];

			if (mX >= 1 && mX <= N && mY >= 1 && mY <= M){
				if (maze[mX][mY] == 1 && visited[mX][mY] > step)
				{
					
					if (visited[mX][mY] != (step + 1)){
						dfs(mX, mY, step + 1);
					}
					
				}
			}
		}
	}
}
int main()
{
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			visited[i][j] = 9999999;
		}
	}

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			scanf("%1d", &maze[i][j]);
		}
	}

	res = 99999999;
	dfs(1, 1, 1);
	printf("%d\n", res);
}