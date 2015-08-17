#include <stdio.h>
#include <string.h>

#define SIZE 101
int board[SIZE][SIZE] = { 0 };
int vis[SIZE][SIZE] = { 0 };

int main(){

	int N, M;
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			scanf("%1d", &board[i][j]);
		}
	}

	int front = 0, rear = 0;
	int q_x[SIZE] = { 0 }, q_y[SIZE] = { 0 };
	int cnt[SIZE] = { 0 };
	int des_x, des_y, count = 0;
	q_x[rear] = 0;
	q_y[rear] = N - 1;
	cnt[rear] = 1;
	rear = (rear + 1) % SIZE;
	des_x = M - 1;
	des_y = 0;

	while (front != rear){
		int pX = q_x[front];
		int pY = q_y[front];
		count = cnt[front];
		front = (front + 1) % SIZE;
		vis[pY][pX] = 1;
		if (pX == des_x && pY == des_y) break;
		count++;


		int tX = pX, tY = pY;
		tX = pX + 1, tY = pY;
		if ( (tX < M && tX >= 0 && tY < N && tY >= 0 ) &&
			vis[tY][tX] == 0 && board[tY][tX] == 0 ){
			//printf("%d %d\n", tY, tX);
			q_x[rear] = tX;
			q_y[rear] = tY;
			cnt[rear] = count;
			rear = (rear + 1) % SIZE;
			vis[tY][tX] = 1;
			if (tY == des_x && tY == des_y) break;
		}
		tX = pX, tY = pY + 1;
		if ((tX < M && tX >= 0 && tY < N && tY >= 0) &&
			vis[tY][tX] == 0 && board[tY][tX] == 0){
			//printf("%d %d\n", tY, tX);
			q_x[rear] = tX;
			q_y[rear] = tY;
			cnt[rear] = count;
			rear = (rear + 1) % SIZE;
			vis[tY][tX] = 1;
			if (tY == des_x && tY == des_y) break;
		}
		tX = pX - 1, tY = pY;
		if ((tX < M && tX >= 0 && tY < N && tY >= 0) &&
			vis[tY][tX] == 0 && board[tY][tX] == 0){
			//printf("%d %d\n", tY, tX);
			q_x[rear] = tX;
			q_y[rear] = tY;
			cnt[rear] = count;
			rear = (rear + 1) % SIZE;
			vis[tY][tX] = 1;
			if (tY == des_x && tY == des_y) break;
		}
		tX = pX, tY = pY - 1;
		if ((tX < M && tX >= 0 && tY < N && tY >= 0) &&
			vis[tY][tX] == 0 && board[tY][tX] == 0){
			//printf("%d %d\n", tY, tX);
			q_x[rear] = tX;
			q_y[rear] = tY;
			cnt[rear] = count;
			rear = (rear + 1) % SIZE;
			vis[tY][tX] = 1;
			if (tY == des_x && tY == des_y) break;
		}
	}


	printf("%d\n", count);

	return 0;
}