#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1111

int graph[SIZE][SIZE];
int visited[SIZE] = { 0 };
int queue[SIZE];
int N, M, V;
int front, rear;

void dfs(int v)
{
	printf("%d ", v);
	visited[v] = 1;

	for (int i = 1; i <= N; i++)
	{
		if (graph[v][i] == 1 && visited[i] == 0)
			dfs(i);
	}
}
int main()
{
	int i, j;
	int a, b;
	int num;

	scanf("%d %d %d", &N, &M, &V);
	for (j = 1; j <= M; j++)
	{
		scanf("%d %d", &a, &b);
		graph[a][b] = graph[b][a] = 1;
	}
	dfs(V);
	
	printf("\n");
	for (i = 1; i <= SIZE; i++)
	{
		visited[i] = 0;
	}

	// BFS
	front = rear = 0;
	queue[rear++] = V;
	visited[V] = 1;
	while (front != rear)
	{
		num = queue[front];

		front++;
		printf("%d ", num);
		for (i = 1; i <= N; i++)
		{
			if (graph[num][i] == 1 && visited[i] == 0) {
				queue[rear++] = i;
				visited[i] = 1;
			}
		}
	}

	printf("\n");
	return 1;
}