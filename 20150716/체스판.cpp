#include <stdio.h>

#define SIZE 1000

int arr[SIZE][SIZE];

int main()
{
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int rows, bomb, cnt;
	int i,j,x,y,t_x,t_y, b_x,b_y;
	int loop;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		cnt = 1;
		scanf("%d %d", &rows, &bomb);

		for (i = 0; i < rows; i++){
			for (j = 0; j < rows; j++){
				scanf("%d", &arr[i][j]);
				if (arr[i][j] == 1)
					arr[i][j] = -1;
			}
		}
		scanf("%d %d", &x, &y);
		

		x--;
		y--;

		b_x = x;
		b_y = y;
		arr[x][y] = 0;

		// left
		t_y = y - 2;
		t_x = x - 1;
		if (t_x >= 0 && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;
		t_x = x + 1;
		if (t_x < rows && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;

		//right
		t_y = y + 2;
		t_x = x - 1;
		if (t_x >= 0 && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;
		t_x = x + 1;
		if (t_x < rows && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;

		// top 
		t_x = x - 2;
		t_y = y - 1;
		if (t_x >= 0 && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;
		t_y = y + 1;
		if (t_x >= 0 && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;

		// bottom
		t_x = x + 2;
		t_y = y - 1;
		if (t_x < rows && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;
		t_y = y + 1;
		if (t_x < rows && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
			arr[t_x][t_y] = arr[x][y] + 1;
		

		while (1)
		{
			for (i = 0; i < rows; i++){
				printf("\n");
				for (j = 0; j < rows; j++){
					printf("%d ", arr[i][j]);
				}
			}
			printf("\n cnt:%d\n", cnt);
			loop = 0;
			for (i = 0; i < rows; i++)
			{
				for (j = 0; j < rows; j++)
				{
					if (arr[i][j] == 0)
						loop++;

					if (arr[i][j] == cnt)
					{
						if (cnt == 1)
							printf("\n%d,%d\n", i, j);
							
						x = i;
						y = j;

						// left
						t_y = y - 2;
						t_x = x - 1;
						if (t_x >= 0 && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;
						t_x = x + 1;
						if (t_x < rows && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;

						//right
						t_y = y + 2;
						t_x = x - 1;
						if (t_x >= 0 && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;
						t_x = x + 1;
						if (t_x < rows && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;

						// top 
						t_x = x - 2;
						t_y = y - 1;
						if (t_x >= 0 && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;
						t_y = y + 1;
						if (t_x >= 0 && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;

						// bottom
						t_x = x + 2;
						t_y = y - 1;
						if (t_x < rows && t_y >= 0 && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;
						t_y = y + 1;
						if (t_x < rows && t_y < rows && arr[t_x][t_y] == 0 && !(t_x == b_x  && t_y == b_y))
							arr[t_x][t_y] = arr[x][y] + 1;

					}
				}
			}
			cnt++;
			if (loop == 1) break;
		}


		for (i = 0; i < rows; i++){
			for (j = 0; j < rows; j++){
				printf("%d ", arr[i][j]);
			}
			printf("\n");
		}
		/*
		while (1)
		{
			for (i = 0; i < rows; i++){
				for (j = 0; j < rows; j++){
					if (arr[i][j]>0 
				}
			}
		}
		*/

		printf("\n");
	}
	return 0;	
}