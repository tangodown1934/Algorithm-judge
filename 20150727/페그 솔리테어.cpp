#include <stdio.h>
#pragma warning(disable:4996)

#define SIZE 11
#define QSIZE 1111111

char MAP[SIZE][SIZE];
int ROW;

int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };

void bfs() {
	int i, j;
	int mX, mY;

	for (i = 0; i < ROW; i++)
	{
		for (j = 0; MAP[i][j] != '\0'; j++)
		{
			if (MAP[i][j] == 'o')
			{

			}
		}
	}
}

int main()
{
	int n, nCount;

	scanf("%d\n", &nCount);

	for (n = 0; n<nCount; n++)
	{
		int i, j;
		ROW = 0;

		while (1)
		{
			gets_s(MAP[ROW]);
			if (MAP[ROW][0] == '\0')
				break;
			ROW++;

		}

		for (i = 0; i < ROW; i++)
		{
			printf("\n%s", MAP[i]);
		}

		bfs();

		printf("\n");
	}

	return 0;
}