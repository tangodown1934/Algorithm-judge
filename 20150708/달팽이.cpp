#pragma warning(disable:4996)
#include <stdio.h>

#define MAX 1111

int N,X;
int snail[MAX][MAX];

void print()
{
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", snail[i][j]);
		}
		printf("\n");
	}
}

int main()
{
	int x, y;
	int i, j;
	int limit, pos;
	int cnt;
	int flag = 1;
	int resX, resY;

	cnt = limit = 1;
	scanf("%d", &N);
	scanf("%d", &X);
	
	x = y = N / 2;
	snail[x][y] = cnt++; // ½ÃÀÛ

	pos = 1;
	while (1)
	{
		for (i = 0; i < limit; i++)
		{
			x = x - pos;
			if (x < 0){
				flag = 0;
				break;
			}
			if (cnt == X)
			{
				resX = x; resY = y;
			}
			snail[x][y] = cnt++;
		}

		if (!flag) // exit
			break;


		for (i = 0; i < limit; i++)
		{
			y = y + pos;
			if (cnt == X)
			{
				resX = x; resY = y;
			}
			snail[x][y] = cnt++;
		}
		pos *= -1; // pivot 
		limit++;
	}
	print();
	printf("%d %d\n", resX+1, resY+1);

	return 0;
}