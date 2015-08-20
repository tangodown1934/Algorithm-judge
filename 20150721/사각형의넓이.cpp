#include <stdio.h>

#define SIZE 111

int map[SIZE][SIZE];

int main()
{
	int itr, nCount;
	int i, j, k;
	int colorCnt;
	int x, y;
	int cnt;

	scanf("%d", &nCount);
	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		scanf("%d", &colorCnt);
		cnt = 0;
		for (i = 1; i <= 100; i++)
		{
			for (j = 1; j <= 100; j++)
			{
				map[i][j] = 0;
			}
		}

		for (i = 0; i < colorCnt; i++)
		{
			scanf("%d %d", &y, &x);

			for (j = x; j < x + 10; j++)
			{
				for (k = y; k < y + 10; k++)
				{
					if (k >= 1 && k <= 100 && j >= 1 && j <= 100)
						map[j][k] = 1;
				}
			}
		}

		for (i = 1; i <= 100; i++)
		{
			for (j = 1; j <= 100; j++)
			{
				if (map[i][j] == 1)
					cnt++;
			}
		}
		printf("%d\n", cnt);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}