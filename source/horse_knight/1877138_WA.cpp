/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 1111

// 체스
int chess[SIZE][SIZE] = { 0 };
// 말 
int horse[SIZE][SIZE] = { 0 };
int h_x[SIZE] = { 0 };
int h_y[SIZE] = { 0 };
int h_c[SIZE];

// 나이트
int night[SIZE][SIZE] = { 0 };
int n_x[SIZE];
int n_y[SIZE];
int n_c[SIZE];


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */


		int rows, bomb;
		int i, j;
		int x, y;
		int front, rear;
		int cnt, res_cnt;

		int popX[] = { -1, +1, -2, -2, -1, +1, +2, +2 }; // l,t,r,b
		int popY[] = { -2, -2, -1, +1, +2, +2, -1, +1 };
		int chX[] = { 0,0, -1, -1, 0, 0, +1, +1 };
		int chY[] = { -1, -1, 0, 0, +1, +1, 0, 0 };

		int t_x, t_y;
		int s_x, s_y;



		scanf("%d %d", &rows, &bomb);
		for (i = 0; i < rows; i++){
			for (j = 0; j < rows; j++){
				scanf("%d", &chess[i][j]);
				if (chess[i][j] == 1) chess[i][j] = -1;
				night[i][j] = chess[i][j];
				horse[i][j] = chess[i][j];
			}
		}
		scanf("%d %d", &x, &y);

		front = rear = cnt = 0;
		x--; y--;
		n_x[rear] = x; // push
		n_y[rear] = y;
		n_c[rear] = cnt;
		
		h_x[rear] = x;
		h_y[rear] = y;
		h_c[rear] = cnt;
		rear++;

		s_x = x;
		s_y = y;

		while (front != rear)
		{
			x = n_x[front]; y = n_y[front]; cnt = n_c[front];
			front++;
			
			night[x][y] = cnt;

			cnt++;
			for (i = 0; i < 8; i++)
			{
				t_x = popX[i] + x;
				t_y = popY[i] + y;


				if (t_x >= 0 && t_x < rows && t_y >= 0 && t_y < rows && night[t_x][t_y] == 0 && night[t_x][t_y] != -1 && !(t_x==s_x && t_y==s_y))
				{
					n_x[rear] = t_x;
					n_y[rear] = t_y;
					n_c[rear] = cnt;
					rear++;
				}
			}
		}


		front = rear = cnt = 0;
		rear++;

		while (front != rear)
		{
			x = h_x[front]; y = h_y[front]; cnt = h_c[front];
			front++;

			horse[x][y] = cnt;

			cnt++;
			for (i = 0; i < 8; i++)
			{
				if (horse[chX[i] + x][chY[i] + y] == -1 || horse[chX[i] + x][chY[i] + y] > horse[x][y])
					continue;

				t_x = popX[i] + x;
				t_y = popY[i] + y;


				if (t_x >= 0 && t_x < rows && t_y >= 0 && t_y < rows && horse[t_x][t_y] == 0 && horse[t_x][t_y] != -1 && !(t_x == s_x && t_y == s_y))
				{
					h_x[rear] = t_x;
					h_y[rear] = t_y;
					h_c[rear] = cnt;
					rear++;
				}
			}
		}

		cnt = 0;
		for (i = 0; i < rows; i++){
			for (j = 0; j < rows; j++)
			{
				if (horse[i][j] == 0)
					cnt++;
				else if (night[i][j] < horse[i][j])
					cnt++;
			}
		}

		printf("%d", cnt-1);

		printf("\n");

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}