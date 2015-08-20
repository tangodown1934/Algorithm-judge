#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 50
#define SWAP(a, b)(a)^=(b)^=(a)^=(b)

int villa[SIZE][SIZE];
int visited[SIZE][SIZE];
int N, M;
int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };
int arr[SIZE] = { 0 };

void dfs(int x, int y, int cnt){
	int i;
	int mX, mY;
	
	arr[cnt]++;
	villa[x][y] = cnt;
	visited[x][y] = 1;
	for (i = 0; i < 4; i++)
	{
		mX = x + pX[i]; mY = y + pY[i];

		if (mX >= 1 && mX <= N && mY >= 1 && mY <= N)
		{
			if (villa[mX][mY] == 1 && visited[mX][mY] == 0)
			{
				dfs(mX, mY,cnt);
			}
		}
	}
}
int main()
{
	int i, j;
	int temp;
	int cnt;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			scanf("%d", &villa[i][j]);
		}
	}
	cnt = 0;

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			if (visited[i][j] == 0 && villa[i][j] == 1)
			{
				dfs(i, j, ++cnt);
			}
		}
	}

	// print
	for (i = 1; i <= cnt; i++)
	{
		for (j = 1; j <= cnt-1; j++)
		{
			if (arr[j] > arr[j+1])
			{
				SWAP(arr[j], arr[j + 1]);
			}
		}
	}

	printf("%d\n", cnt); // °³¼ö 
	for (i = 1; i <= cnt; i++)
	{
		printf("%d\n", arr[i]);
	}
}