#include <stdio.h>
#include <algorithm>
using namespace std;

int N;
int matrix[100][100];
int visit[100][100];
int home[100];
int cnt;

int delX[4] = { 0, 0, 1, -1 };
int delY[4] = { 1, -1, 0, 0 };

void DFS(int x, int y)
{
	visit[x][y] = 1;
	home[cnt]++;
	
	for (int i = 0; i < 4; i++)
	{
		if (!visit[x + delX[i]][y + delY[i]] && matrix[x+delX[i]][y+delY[i]]) 
			DFS(x + delX[i], y + delY[i]);
	}
}

int main()
{
	scanf("%d", &N);

	for (int i = 0; i <= N + 1; i++)
	{
		for (int j = 0; j <= N + 1; j++)
		{
			matrix[i][j] = 0;
		}
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			scanf("%d", &matrix[i][j]);
		}
	}

	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (visit[i][j] == 0 && matrix[i][j])
			{
				cnt++;
				DFS(i, j);
			}
		}
	}

	printf("%d\n", cnt);
	sort(home + 1, home + cnt+1);
	for (int i = 0; i < cnt; i++)
		printf("%d\n", home[i+1]);
	return 0;
}