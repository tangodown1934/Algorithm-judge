#pragma warning(disable:4996)
#include <stdio.h>

/*
제일 중요한 2가지
1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
2. 배열의 사이즈

*/

#define SIZE 111111

int res[SIZE];
int map[111][111];
int tempMap[111][111];
int visited[111][111];
int N, HEIGH;

int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };

typedef struct q
{
	int x[SIZE];
	int y[SIZE];
	int front;
	int rear;
}q;

q queue;

void push(q *queue, int x, int y)
{
	if (queue->front - 1 == queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->x[queue->rear] = x;
	queue->y[queue->rear] = y;
	queue->rear = (queue->rear + 1) % SIZE;
}

void pop(q *queue)
{
	queue->front++;
	queue->front %= SIZE;
}

int empty(q *queue)
{
	if (queue->front == queue->rear)
	{
		return 1;
	}
	return 0;
}
void print()
{
	printf("\n");
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", tempMap[i][j]);
		}
		printf("\n");
	}
}
void bfs(int x, int y)
{
	int mX, mY;
	int here;

	push(&queue, x, y);
	visited[x][y] = 1;

	while (!empty(&queue)){
		x = queue.x[queue.front];
		y = queue.y[queue.front];
		pop(&queue);
		visited[x][y] = 1;

		for (int i = 0; i < 4; i++)
		{
			mX = x + pX[i];
			mY = y + pY[i];

			if (mX >= 0 && mX < N &&mY >= 0 && mY < N)
			{
				if (tempMap[mX][mY] == 1 && visited[mX][mY] == 0)
					push(&queue, mX, mY);
			}
		}
	}
}
int main()
{
	int nCount;
	int i, j, k;
	int x, y;
	int cnt;
	int max;
	int res;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
		}
	}
	res = max = 0;
	for (k = 0; k <= 100; k++){
		cnt = 0;
		HEIGH = k;
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				visited[i][j] = 0; // Initialize 

				if (map[i][j] < HEIGH)
					tempMap[i][j] = 0; // 침수
				else
					tempMap[i][j] = 1; // 위로 
			}
		}
		for (i = 0; i < N; i++)
		{
			for (j = 0; j < N; j++)
			{
				if (tempMap[i][j] == 1 && visited[i][j] == 0){
					cnt++;
					bfs(i, j);
				}
			}
		}
		if (max < cnt)
			max = cnt;
		if (res < max)
			res = max;
	}
	printf("%d\n", res);

	return 1;
}
