#include <stdio.h>

bool visited[10];
int graph[10][10];

void dfs(int i)
{
	visited[i] = true;
	//i번과 인접한 정점을 탐색
	printf("%d ", i);
	for (int next = 0; next < 10; next++)
	{
		if (!visited[next] && graph[i][next])
		{
			
			dfs(next);
		}
	}
}

int main()
{
	int V;
	int start;
	int v1, v2, add;
	scanf("%d %d", &V, &start);
	
	while (1)
	{
		int ret = scanf("%d %d", &v1, &v2);
		if (ret == -1) break;
		graph[v1][v2] = graph[v2][v1] = 1;
	}

	dfs(start);
	printf("\n");
	return 0;
}