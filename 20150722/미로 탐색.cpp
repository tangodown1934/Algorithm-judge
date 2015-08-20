#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111

int computer[SIZE][SIZE];
int N;
int CNT;
int virusCnt;
bool visited[SIZE];

void dfs(int s){
	visited[s] = true;
	printf("%d ", s);

	for (int i = 1; i <= N; i++)
	{
		if (computer[s][i] == 1 && visited[i] == false)
		{
			dfs(i);
		}
	}
}
int main()
{
	int i;
	int a, b;

	scanf("%d %d", &N, &CNT);;

	for (i = 1; i <= N; i++){ visited[i] = false; }

	for (i = 0; i < CNT; i++)
	{
		scanf("%d %d", &a, &b);
		computer[a][b] = computer[b][a] = 1;
	}

	dfs(1);
	printf("\n");
}