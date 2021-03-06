/*

VC, GCC에서 사용

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 111

int arr[SIZE][SIZE];
int visited[SIZE];
int n, pairCnt;
int cnt;

void dfs(int v)
{
	visited[v] = 1;

	for (int i = 1; i <= n; i++)
	{
		if (visited[i] == 0 && arr[v][i] == 1)
		{
			dfs(i);
			cnt++;
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */



		int i, j;
		int x, y;
		cnt = 0;

		scanf("%d", &n);
		scanf("%d", &pairCnt);

		for (i = 1; i <= n; i++){ for (j = 0; j < n; j++){ arr[i][j] = 0; } } // 초기화 
		for (i = 1; i <= n; i++){ visited[i] = 0; } // 초기화 

		for (i = 1; i <= pairCnt; i++)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = arr[y][x] = 1;
		}

		dfs(1);

		printf("%d", cnt);
		printf("\n");

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}