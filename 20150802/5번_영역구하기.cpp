#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111111
#define MAPSIZE 111

typedef struct position{
	int lx,ly;
	int rx,ry;
}position;

int M, N, K;
int MAP[MAPSIZE][MAPSIZE];
position pos[SIZE];

int qX[SIZE];
int qY[SIZE];
int qCnt[SIZE];
int front, rear;
int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };
int visited[MAPSIZE][MAPSIZE];
int cnt;

int res[SIZE];

void print()
{
	printf("\n");
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			printf("%d ", MAP[i][j]);
		}
		printf("\n");
	}
}
void bfs(int initX, int initY){
	int i,j;
	int mX, mY;
	int x, y;

	qX[rear] = initX;
	qY[rear] = initY;
	qCnt[rear] = cnt;
	rear++;

	visited[initX][initY] = 1; // 방문처리
	while (front != rear)
	{
		x = qX[front];
		y = qY[front];
		cnt = qCnt[front];
		front++;

		MAP[x][y] = cnt; // 번호 붙이기
		for (i = 0; i < 4; i++){
			mX = x + pX[i];
			mY = y + pY[i];
			if (mX >= 0 && mX < M && mY >= 0 && mY < N){
				if (visited[mX][mY] == 0 && MAP[mX][mY] != -1){ // 방문하지 않았고 색칠하지 않은 곳
					qX[rear] = mX;
					qY[rear] = mY;
					qCnt[rear] = cnt;
					rear++;

					visited[mX][mY] = 1;
				}
			}
		}
	}
}

void fill(){
	int i,j,l;
	
	for (i = 0; i < K; i++)
	{
		for (l = pos[i].ly; l < pos[i].ry; l++){
			for (j = pos[i].lx; j < pos[i].rx; j++){ // 색칠
				MAP[j][l] = -1;
			}
		}
		//print();
	}
}

int main()
{
	int i, j, l;

	scanf("%d %d %d", &M, &N, &K);
	for (i = 0; i < K; i++)
	{
		scanf("%d %d %d %d", &pos[i].ly, &pos[i].lx, &pos[i].ry, &pos[i].rx);
	}

	// init
	front = rear = 0;
	cnt = 1;
	for (i = 0; i < M; i++)
	{
		for (j = 0; j < N; j++)
		{
			visited[i][j]= MAP[i][j] = 0;
		}
	}

	fill();

	for (i = 0; i < M; i++){
		for (j = 0; j < N; j++){
			if (visited[i][j] == 0 && MAP[i][j] != -1){ // 방문하지 않았다면
				bfs(i, j);
				cnt++;
			}
		}
	}

	int totalCnt;
	for (i = 1; i < cnt; i++)
	{
		totalCnt = 0;
		for (j = 0; j < M; j++)
		{
			for (l = 0; l < N; l++)
			{
				if (MAP[j][l] == i){
					totalCnt++;
				}
			}
		}
		res[i] = totalCnt;
	}

	int temp;
	for (i = 1; i < cnt; i++)
	{
		for (j = 1; j < cnt - 1; j++)
		{
			if (res[j] > res[j + 1]){
				temp = res[j];
				res[j] = res[j + 1];
				res[j + 1] = temp;
			}
		}
	}

	//print();
	printf("%d\n", cnt - 1);
	for (i = 1; i < cnt; i++)
		printf("%d ", res[i]);


	return 0;
}
