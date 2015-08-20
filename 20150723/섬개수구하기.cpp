#pragma warning(disable:4996)
#include <stdio.h>

/*
제일 중요한 2가지
1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
2. 배열의 사이즈

*/

#define SIZE 200

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int res[SIZE];

int W, H;

int pX[] = { 0, -1, -1, -1, 0, +1, +1, +1 };
int pY[] = { -1, -1, 0, +1, +1, +1, 0, -1 };

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
	for (int i = 1; i <= H; i++)
	{
		for (int j = 1; j <= W; j++)
		{
			printf("%d ", map[i][j]);
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
		//map[x][y] = 9;
		//print();
		for (int i = 0; i < 8; i++)
		{
			mX = x + pX[i];
			mY = y + pY[i];

			if (mX >= 1 && mX <= H &&mY >= 1 && mY <= W)
			{
				if (map[mX][mY] == 1 && visited[mX][mY] == 0)
				{
					push(&queue, mX, mY);
				}
			}
		}
	}
}
int main()
{
	int i, j;
	int cnt;

	while (1)
	{
		cnt = 0;
		scanf("%d %d", &W, &H);

		if (W == 0 && H == 0)
			break;

		for (i = 1; i <= H; i++)
		{
			for (j = 1; j <= W; j++)
			{
				scanf("%d", &map[i][j]);
				visited[i][j] = 0;
			}
		}

		for (i = 1; i <= H; i++)
		{
			for (j = 1; j <= W; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0){
					cnt++;
					bfs(i, j);
				}
			}
		}
		printf("%d\n", cnt);
	}
}
