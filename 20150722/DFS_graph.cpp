#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 33

bool visited[SIZE] = { false };

int START;
int N; // ������ ����
int mygraph[SIZE][SIZE] = { 0 };

void dfs(int s)
{
	printf("%d\n", s);
	visited[s] = true;

	for (int i = START; i <= N; i++) // ���� �ͺ��� ���� (�켱����)
	{
		if (mygraph[s][i] == 1 && visited[i] == false)
		{
			dfs(i);
		}
	}
}
int main()
{
	int a, b;
	int i;

	scanf("%d %d", &N, &START);

	for (i = START; i <= N; i++)
	{
		visited[i] = false;
	}

	while (scanf("%d %d", &a, &b)!=EOF)
	{
		mygraph[a][b] = mygraph[b][a] = 1;
	}

	dfs(START);
}