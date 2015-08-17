#define _CRT_SECURE_NO_WARNINGS

/*

VC, GCC에서 사용

*/

#include <stdio.h>

typedef struct __pos_t {
	int y, x;
	int time;
} pos_t;

int main()
{

	pos_t dir[4];

	dir[0].y = 1; dir[0].x = 0;
	dir[1].y = 0; dir[1].x = 1;
	dir[2].y = -1; dir[2].x = 0;
	dir[3].y = 0; dir[3].x = -1;
		int i, j, time = 0;
		int row, col;
		int maze[20][20];
		pos_t queue[1024];
		int front = -1, rear = -1;
		pos_t here, there;
		int ans = -1;
		int temp;



		scanf("%d %d", &row, &col);

		for (i = 0; i < 20; i++)
			for (j = 0; j < 20; j++)
				maze[i][j] = 0;

		for (i = 0; i < row; i++) {
			j = 1;
			scanf("%d", &temp);
			while (temp != 0) {
				maze[i][col - j] = temp % 10;
				j++; temp = temp / 10;
			}
		}
		/*
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++)
				printf("%d ", maze[i][j]);
			printf("\n");
		}
		*/

		queue[++rear].y = row - 1;
		queue[rear].x = 0;
		queue[rear].time = 1;
		maze[row - 1][0] = 1;

		while (front < rear) {
			here.y = queue[++front].y;
			here.x = queue[front].x;
			time = queue[front].time;

			for (i = 0; i < 4; i++) {
				there.y = here.y + dir[i].y;
				there.x = here.x + dir[i].x;
				if (there.y >= 0 && there.y < row && there.x >= 0 && there.x < col) {
					if (maze[there.y][there.x] == 0) {
						if (there.y == 0 && there.x == col - 1) ans = time + 1;
						queue[++rear].y = there.y;
						queue[rear].x = there.x;
						queue[rear].time = time + 1;
						maze[there.y][there.x] = 1;
					}
				}
			}
		}

		printf("%d\n", ans);
	

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}