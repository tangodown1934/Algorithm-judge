#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111
#define QSIZE 111111

int map[SIZE][SIZE];
int visited[SIZE][SIZE];
int W, H;
int X, Y;

int qX[QSIZE];
int qY[QSIZE];
int qSec[QSIZE];
int front, rear;

int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };
int main()
{
	int itr, nCount;
	int i, j;
	int x, y;
	int mX, mY;
	int sec;
	int totalCnt;
	int juglingCnt;

	scanf("%d", &nCount);

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);


		front = rear = 0;
		sec = 3;
		totalCnt = juglingCnt = 0;
		scanf("%d %d", &W, &H);
		for (i = 1; i <= H; i++)
		{
			for (j = 1; j <= W; j++)
			{
				scanf("%1d", &map[i][j]);
				if (map[i][j] == 1)
					totalCnt++;
				visited[i][j] = 0;
			}
		}
		scanf("%d %d", &Y, &X);

		qX[rear] = X;
		qY[rear] = Y;
		qSec[rear] = sec;
		rear = (rear + 1) % QSIZE;
		visited[X][Y] = 1;

		while (front != rear)
		{
			x = qX[front]; // pop
			y = qY[front];
			sec = qSec[front];
			front = (front + 1) % QSIZE;

			map[x][y] = sec;

			juglingCnt++;
			for (i = 0; i < 4; i++){
				mX = x + pX[i];
				mY = y + pY[i];

				if (mX >= 1 && mX <= H && mY >= 1 && mY <= W)
				{
					if (visited[mX][mY] == 0 && map[mX][mY] == 1)
					{
						qX[rear] = mX;
						qY[rear] = mY;
						qSec[rear] = sec+1;
						rear = (rear + 1) % QSIZE;
						visited[mX][mY] = 1;
					}
				}
			}
		}

		printf("%d %d\n", sec,totalCnt-juglingCnt);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}