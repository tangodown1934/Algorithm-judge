5 7
WLLWWWL
LLLWLLL
LWLWLWW
LWLWLLL
WLLLWWW

#include <stdio.h>
#include <Windows.h>

/*
���� �߿��� 2����
1. pop �����ϱ� ������ ������ empty���� Ȯ�� �ϰ� pop
2. �迭�� ������

*/

#define SIZE 200

int mapTemp[SIZE][SIZE];
int visitedTemp[SIZE][SIZE];

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int W, H;

int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };

typedef struct q
{
	int x[SIZE];
	int y[SIZE];
	int cnt[SIZE];
	int front;
	int rear;
}q;

q queue;

void push(q *queue, int x, int y, int cnt)
{
	if (queue->front - 1 == queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->x[queue->rear] = x;
	queue->y[queue->rear] = y;
	queue->cnt[queue->rear] = cnt;
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
int bfs(int x, int y, int cnt)
{
	int mX, mY;

	push(&queue, x, y, cnt);
	visited[x][y] = 1;

	while (!empty(&queue)){
		x = queue.x[queue.front];
		y = queue.y[queue.front];
		cnt = queue.cnt[queue.front];

		map[x][y] = cnt;
		pop(&queue);
		//print();
		for (int i = 0; i < 4; i++)
		{
			mX = x + pX[i];
			mY = y + pY[i];

			if (mX >= 0 && mX < H &&mY >= 0 && mY < W)
			{
				if (map[mX][mY] == 1 && visited[mX][mY] == 0){
					push(&queue, mX, mY, map[x][y] + 1);
					visited[mX][mY] = 1;
				}
			}
		}
	}
	return cnt;
}
int main()
{
	int nCount;
	int i, j, k;
	int n, m;
	int cnt;
	int max;
	int res;
	char temp[100];

	scanf("%d", &nCount);
	for (k = 0; k < nCount; k++)
	{
		scanf("%d %d", &H, &W);

		for (i = 0; i < H; i++)
		{
			scanf("%s", temp);
			for (j = 0; j < W; j++)
			{
				visited[i][j] == 0; // Initialize 
				if (temp[j] == 'L'){
					mapTemp[i][j] = 1;
				}
				else if (temp[j] == 'W'){
					mapTemp[i][j] = 0;
				}
			}
		}
		res = 0;
		for (n = 0; n < H; n++){
			for (m = 0; m < W; m++){
				max = 0; // Initialize
				for (i = 0; i < H; i++){
					for (j = 0; j < W; j++)
					{
						map[i][j] = mapTemp[i][j];
						visited[i][j] = 0;
					}
				}

				for (i =n; i < H; i++){
					for (j = m; j < W; j++)
					{
						if (map[i][j] == 1 && visited[i][j] == 0){
							cnt = bfs(i, j, 0);
							if (max < cnt)
								max = cnt;
						}
					}
				}
				if (max > res)
					res = max;
			}
		}
		printf("%d\n", res);
	}
	system("pause");
	return 1;
}
