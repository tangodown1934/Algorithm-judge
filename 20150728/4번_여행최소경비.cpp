#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 22

int visited[SIZE];
int MAP[SIZE][SIZE];
int N;
int minValue;

void sol(int idx, int sum, int cnt)
{
	int i;

	if (cnt == N+1)
	{
		sum += MAP[idx][1]; // 집으로 돌아가는 경비
		
		if (sum < minValue)
			minValue = sum;

		//printf("res : %d\n", sum);
		sum = 0;
		return;
	}

	for (i = 1; i <= N; i++)
	{
		if (visited[i] == 0 && MAP[idx][i] != 0)
		{
			sum = sum + MAP[idx][i];
			//printf("sum : %d, idx : %d, i : %d\n", sum, idx, i);
			// 방문처리
			visited[i] = 1;
			cnt++;
			sol(i, sum, cnt);

			// 다시 세팅
			sum = sum - MAP[idx][i];
			visited[i] = 0;
			cnt--;
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	int i, j;

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		minValue = 0;

		scanf("%d", &N);

		// init
		for (i = 1; i <= N; i++)
		{
			visited[i] = 0;
		}

		// input - 집은 1번
		for (i = 1; i <= N; i++)
		{
			for (j = 1; j <= N; j++)
			{
				scanf("%d", &MAP[i][j]);
				minValue += MAP[i][j];
			}
		}

		// init 
		visited[1] = 1; // 집은 셀필요없다
		sol(1, 0, 2);

		printf("%d\n", minValue);
	}
	
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}