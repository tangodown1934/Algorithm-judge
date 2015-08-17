#include <stdio.h>
#include <string.h>

#define SIZE 101

int com[SIZE][SIZE] = { 0 };
int vis[SIZE] = { 0 };

int N, L, x, y;


int main(){
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	//for (itr = 0; itr<nCount; itr++)
	//{
		memset(com, 0, sizeof(com));
		memset(vis, 0, sizeof(vis));

		//printf("#testcase%d\n", itr + 1);
		scanf("%d %d", &N, &L);

		for (int i = 0; i < L; i++)
		{
			scanf("%d %d", &x, &y);
			com[y][x] = com[x][y] = 1;
		}

		//큐 시작
		//큐 초기화
		int front = 0, rear = 0, cnt = 0;
		int q[SIZE] = { 0 };
		q[rear] = 1;
		rear = (rear + 1) % SIZE;
		vis[1] = 1;

		while (front != rear){
			int tmp = q[front];
			front = (front + 1) % SIZE;
			for (int i = 2; i <= N; i++)
			{
				if (com[tmp][i] == 1 && vis[i] == 0){
					//큐에 넣기
					q[rear] = i;
					rear = (rear + 1) % SIZE;
					vis[i] = 1;
					cnt++;
				}
			}
		}

		printf("%d\n", cnt);
	//}

	return 0;
}