#include <stdio.h>
#pragma warning(disable:4996)

#define SIZE 444
#define QSIZE 2222

int N, M;
int good[SIZE][SIZE];
int goodCnt[SIZE];
int q[QSIZE];
int visited[SIZE];

int front, rear;

void printHelper()
{
	int i, j;

	printf("\n");
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			printf("%d", good[i][j]);
		}
		printf("\n");
	}
}
void bfs()
{
	int i,j;
	int pop;
	int cnt;

	front = rear = 0;
	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= N; j++)
		{
			visited[j] = 0;
		}
		visited[i] = 1;
		cnt = 1;

		// PUSH
		q[rear] = i;
		rear = (rear + 1) % QSIZE;

		while (front != rear)
		{
			// POP
			pop = q[front];
			front = (front + 1) % QSIZE;

			for (j = 1; j <= N; j++)
			{
				if (good[j][pop] == 1 && visited[j]==0){
					cnt++;

					q[rear] = j;
					rear = (rear + 1) % QSIZE;

					visited[j] = 1;
				}
			}
		}
		q[rear] = i;
		rear = (rear + 1) % QSIZE;

		while (front != rear)
		{
			// POP
			pop = q[front];
			front = (front + 1) % QSIZE;

			for (j = 1; j <= N; j++)
			{
				if (good[pop][j] == 1 && visited[j]==0){
					cnt++;

					q[rear] = j;
					rear = (rear + 1) % QSIZE;

					visited[j] = 1;
				}
			}
		}

		goodCnt[i] = N - cnt;
	}

}

int main()
{
	int i,j;
	int x, y;

	scanf("%d", &N);
	scanf("%d", &M);

	for (i = 1; i <= N; i++)
	{
		for (j = 1; j <= M; j++)
		{
			good[i][j] = 0;
		}
	}

	for (i = 1; i <= M; i++)
	{
		scanf("%d %d", &x, &y);
		good[x][y] = 1;
	}

	//printHelper();
	bfs();

	for (i = 1; i <= N; i++){
		printf("%d\n", goodCnt[i]);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}