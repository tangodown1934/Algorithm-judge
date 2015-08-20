#include <stdio.h>
#include <Windows.h>

/*
제일 중요한 2가지
1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
2. 배열의 사이즈

*/

#define SIZE 444

int chess[SIZE][SIZE];
int I, sX, sY, dX, dY;

int pX[] = { -1, -2, -2, -1, +1, +2, +2, +1 };
int pY[] = { -2, -1, +1, +2, +2, +1, -1, -2 };

typedef struct q
{
	int data[SIZE];
	int time[SIZE];
	int front;
	int rear;
}q;

q queue;

void push(q *queue, int data, int time)
{
	if (queue->front - 1 == queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->data[queue->rear] = data;
	queue->time[queue->rear] = time;
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
int front(q *queue)
{
	return queue->data[queue->front];
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
void dfs(int x, int y, int step)
{
	int mX, mY;

	chess[x][y] = step;
	//print();
	if (x == dX && y == dY)
	{
		return;
	}
	step++;
	for (int i = 0; i < 8; i++)
	{
		mX = x + pX[i]; mY = y + pY[i];
		if (mX >= 0 && mX < I && mY >= 0 && mY < I){
			if (chess[mX][mY] > step){
				dfs(mX, mY, step);
			}
		}
	}
	
}
int main()
{
	int nCount;
	int n;
	int i, j, k;

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
				chess[i][j] = 99999;
			}
		}

		dfs(sX, sY, 0);
		printf("%d\n", chess[dX][dY]);
	}
	system("pause");
	return 1;
}
