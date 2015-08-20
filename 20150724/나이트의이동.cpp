#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1111111

int chess[333][333];
int visited[333][333];
int I, sX, sY, dX, dY;

int pX[] = { -1, -2, -2, -1, +1, +2, +2, +1 };
int pY[] = { -2, -1, +1, +2, +2, +1, -1, -2 };

typedef struct q
{
	int x[SIZE];
	int y[SIZE];
	int step[SIZE];
	int front;
	int rear;
}q;

q queue;

void push(q *queue, int x, int y, int step)
{
	if (queue->front - queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->x[queue->rear] = x;
	queue->y[queue->rear] = y;
	queue->step[queue->rear] = step;
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
	for (int i = 0; i < I; i++)
	{
		for (int j = 0; j < I; j++)
		{
			printf("%d ", chess[i][j]);
		}
		printf("\n");
	}
}
void bfs()
{
	int x, y, step;
	int mX, mY;

	queue.front = queue.rear = 0;
	push(&queue, sX, sY, 0);
	visited[sX][sY] = 1;
	while (!(empty(&queue)))
	{
		x = queue.x[queue.front];
		y = queue.y[queue.front];
		step = queue.step[queue.front];
		pop(&queue);

		chess[x][y] = step;

		if (x == dX && y == dY)
			break;

		for (int i = 0; i < 8; i++)
		{
			mX = x + pX[i]; mY = y + pY[i];
			if (mX >= 0 && mX < I && mY >= 0 && mY < I){
				if (visited[mX][mY] == 0){
					push(&queue, mX, mY, step + 1);
					visited[mX][mY] = 1;
				}
			}
		}
	}
}
int main()
{
	int nCount;
	int n;
	int i, j;

	scanf("%d", &nCount);
	for (n = 0; n < nCount; n++)
	{
		scanf("%d", &I);
		scanf("%d %d", &sX, &sY);
		scanf("%d %d", &dX, &dY);

		for (i = 0; i < I; i++)
		{
			for (j = 0; j < I; j++)
			{
				chess[i][j] = 0;
				visited[i][j] = 0;
			}
		}

		bfs();
		printf("%d\n", chess[dX][dY]);
	}
	return 1;
}
