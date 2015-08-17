/*

VC, GCC���� ���

*/

#include <stdio.h>

#define SIZE 100

int arr[SIZE][SIZE];
int visited[SIZE];
int n, pairCnt;
int cnt;
int q[SIZE];
int front, rear;

void bfs()
{
	while (front != rear)
	{
		int v = q[front++];
		
		cnt++;

		for (int i = 1; i <= n; i++)
		{
			if (visited[i] == 0 && arr[v][i] == 1)
			{
				q[rear++] = i;
				visited[i] = 1;
			}
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	

		int i, j;
		int x, y;
		
		front = rear = cnt = 0;

		scanf("%d", &n);
		scanf("%d", &pairCnt);

		for (i = 1; i <= n; i++){ for (j = 0; j < n; j++){ arr[i][j] = 0; } } // �ʱ�ȭ 
		for (i = 1; i <= n; i++){ visited[i] = 0; } // �ʱ�ȭ 

		for (i = 1; i <= pairCnt; i++)
		{
			scanf("%d %d", &x, &y);
			arr[x][y] = arr[y][x] = 1;
		}

		q[rear++] = 1;
		visited[1] = 1;

		bfs();

		printf("%d", cnt-1);

		printf("\n");

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}