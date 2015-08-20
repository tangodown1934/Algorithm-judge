#include <stdio.h>

#define SIZE 100

int qX[SIZE];
int qY[SIZE];
int qC[SIZE];

int popX[] = { 0, -1, 0, +1 }; // L, T, R, B
int popY[] = { -1, 0, +1, 0 };

int arr[SIZE][SIZE] = { 0 };
int visited[SIZE][SIZE] = { 0 };

int main()
{
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf_s("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);
		
		int x, y;
		int row, col;
		int i, j;
		int front, rear;
		int cnt;
		int tX, tY;
		int max;

		front = rear = 0;
		cnt = 1;

		scanf_s("%d %d", &col, &row);
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				scanf_s("%d", &arr[i][j]);
				visited[i][j] = 0;
			}
		}
		scanf_s("%d %d", &y, &x);
		
		x--; y--;
		qX[rear] = x;
		qY[rear] = y;
		qC[rear] = 1;
		rear++;

		visited[x][y] = 1;

		while (front!=rear)
		{
			x = qX[front];
			y = qY[front];
			cnt = qC[front];
			front++;
			
			arr[x][y] = cnt;// Drawing

			for (i = 0; i < 4; i++)
			{
				tX = popX[i] + x; tY = popY[i] + y;

				if (tX >= 0 && tX < row && tY >= 0 && tY < col){
					if (arr[tX][tY] == 1 && visited[tX][tY] == 0)
					{
						qX[rear] = tX;
						qY[rear] = tY;
						qC[rear] = cnt + 1;
						rear++;
						visited[tX][tY] = 1;
					}
				}
			}

		}

		max = 1;
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (max < arr[i][j])
					max = arr[i][j];
			}
		}
		printf("%d", max);

		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}
