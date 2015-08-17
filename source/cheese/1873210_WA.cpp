#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct __pos_t {
	int y, x;
} pos_t;

pos_t dir[4];

void floodfill(int mat[100][100], int exposure[100][100], int row, int col, int y, int x) {
	pos_t temp;
	int i;

	if (y >= 0 && y < row && x >= 0 && x < col) {
		if (exposure[y][x] == -1) {
			exposure[y][x] = 0;
			// Count how many face is exposed
			for (i = 0; i < 4; i++) {
				temp.y = y + dir[i].y;
				temp.x = x + dir[i].x;
				if (mat[temp.y][temp.x] == 0)
					exposure[y][x]++;
			}
			if (mat[y][x] == 0) exposure[y][x] = -2;
			// floodfill 4 Direction
			for (i = 0; i < 4; i++) {
				temp.y = y + dir[i].y;
				temp.x = x + dir[i].x;
				floodfill(mat, exposure, row, col, temp.y, temp.x);
			}
		}
		
	}

}

int main() {

	int mat[100][100];
	int exposure[100][100];
	int i, j, row, col, isMelting = FALSE;
	int time = 0;

	dir[0].y = 1; dir[0].x = 0;
	dir[1].y = 0; dir[1].x = 1;
	dir[2].y = -1; dir[2].x = 0;
	dir[3].y = 0; dir[3].x = -1;

	scanf("%d %d", &row, &col);

	for (i = 0; i < row; i++) 
		for (j = 0; j < col; j++)
			scanf("%d", &mat[i][j]);

	do {
		isMelting = FALSE;
		for (i = 0; i < row; i++)
			for (j = 0; j < col; j++)
				exposure[i][j] = -1;

		floodfill(mat, exposure, row, col, 0, 0);
		/*
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++)
				printf("%d ", exposure[i][j]);
			printf("\n");
		}
		printf("\n");
		*/
		for (i = 0; i < row; i++) {
			for (j = 0; j < col; j++)
				if (exposure[i][j] >= 2) {
					isMelting = TRUE;
					mat[i][j] = 0;
				}
		}
		if(isMelting) time++;
	} while (isMelting);

	printf("%d\n", time);

	return 0;
}