#include <stdio.h>
#include <Windows.h>

/*
	제일 중요한 2가지
	1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
	2. 배열의 사이즈

	*/

#define SIZE 200

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int W, H, COUNT;

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
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < W; j++)
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

		//map[x][y] = -1; // 그냥 체크함
		for (int i = 0; i < 4; i++)
		{
			mX = x + pX[i];
			mY = y + pY[i];

			if (mX >= 0 && mX < H &&mY >= 0 && mY < W)
			{
				if (map[mX][mY] == 1 && visited[mX][mY] == 0)
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

	scanf("%d", &nCount);
	for (k = 0; k < nCount; k++)
	{
		cnt = 0;
		scanf("%d %d %d", &W, &H, &COUNT);

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				map[i][j] = visited[i][j] = 0; // Initialize 
			}
		}

		for (i = 0; i < COUNT; i++)
		{
			scanf("%d %d", &x, &y); // Check on the map 
			map[x][y] = 1; 
		}

		for (i = 0; i < H; i++)
		{
			for (j = 0; j < W; j++)
			{
				if (map[i][j] == 1 && visited[i][j] == 0){
					cnt++;
					bfs(i, j);
					//print();
				}
			}
		}
		printf("%d\n", cnt);
	}
	system("pause");
	return 1;
}
