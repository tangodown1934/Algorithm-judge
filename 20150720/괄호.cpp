#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 50

int arr[SIZE];
int check[SIZE];
int chr[SIZE];

int res[111111][SIZE];

int n;
int cnt;

void count(int idx, int chx)
{
	int i;

	if (idx == n + 1)
	{
		for (i = 0; i <= n; i++)
		{
			res[cnt][i] = arr[i];
		}
		cnt++;
	}

	for (i = 0; i <= 9; i++)
	{
		if (check[i] == 0) // 미방문시
		{
			if (idx == 0){
				arr[idx] = i;
				check[i] = 1;

				count(idx + 1, chx);
			}else if (idx >= 1 && chr[chx] == '<')
			{
				if (arr[idx - 1] < i)
				{
					arr[idx] = i;
					check[i] = 1;

					count(idx + 1, chx + 1);
				}
			}else if (idx >= 1 && chr[chx] == '>')
			{
				if (arr[idx - 1] > i)
				{
					arr[idx] = i;
					check[i] = 1;
					count(idx + 1, chx + 1);
				}
			}
			check[i] = 0;
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int i,j;

		scanf("%d", &n);

		for (i = 0; i < n; i++)
		{
			scanf(" %c", &chr[i]);
		}

		// init
		for (i = 0; i < 20; i++){
			check[i] = 0;
		}

		cnt = 0;
		count(0, 0);

		for (i = 0; i <= n; i++){
			printf("%d", res[cnt - 1][i]);
		}
		printf("\n");
		for (i = 0; i <= n; i++){
			printf("%d", res[0][i]);
		}
		printf("\n");
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}