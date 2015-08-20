#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define TRUE 1
#define FALSE 0

int vert_chk(int mat[9][9], int x) {
	int i, y;
	int chk[10];
	for (i = 0; i < 10; i++) chk[i] = FALSE;
	for (y = 0; y < 9; y++) {
		if (mat[y][x] == 0) continue;
		if (chk[mat[y][x]] == FALSE) chk[mat[y][x]] = TRUE;
		else return FALSE;
	}
	return TRUE;
}

int horz_chk(int mat[9][9], int y) {
	int i, x;
	int chk[10];
	for (i = 0; i < 10; i++) chk[i] = FALSE;
	for (x = 0; x < 9; x++) {
		if (mat[y][x] == 0) continue;
		if (chk[mat[y][x]] == FALSE) chk[mat[y][x]] = TRUE;
		else return FALSE;
	}
	return TRUE;
}

int square_chk(int mat[9][9], int y, int x) {
	int i, j, y_start, x_start;
	int chk[10];
	for (i = 0; i < 10; i++) chk[i] = FALSE;
	y_start = y - y % 3;
	x_start = x - x % 3;

	for (i = y_start; i < y_start + 3; i++) {
		for (j = x_start; j < x_start + 3; j++) {
			if (mat[i][j] == 0) continue;
			if (chk[mat[i][j]] == FALSE) chk[mat[i][j]] = TRUE;
			else return FALSE;
		}
	}
	return TRUE;
}

void sudoku(int mat[9][9], int y, int x, int* f) {
	int i;
	if (y == 9) {
		*f = TRUE;
		return;
	}

	if (mat[y][x] > 0) {
		// step into
		if(x < 8) sudoku(mat, y, x + 1, f);
		else if(x == 8) sudoku(mat, y + 1, 0, f);
	}
	// Fill the blank
	else if (mat[y][x] == 0) {
		for (i = 1; i <= 9; i++) {
			mat[y][x] = i;
			if (vert_chk(mat, x) && horz_chk(mat, y) && square_chk(mat, y, x)) {
				// step into
		 		if (x < 8) sudoku(mat, y, x + 1, f);
				else if (x == 8) sudoku(mat, y + 1, 0, f);
			}
			if (*f == TRUE) return;
			mat[y][x] = 0;
		}
	}
}

int main() {
	int i, j, f = FALSE;
	int mat[9][9];
	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++) {
			scanf("%1d", &mat[i][j]);
		}
	}

	sudoku(mat, 0, 0, &f);

	
	for (i = 0; i < 9; i++) {
		for (j = 0; j < 9; j++)
			printf("%d", mat[i][j]);
		printf("\n");
	}
	

	return 0;
}