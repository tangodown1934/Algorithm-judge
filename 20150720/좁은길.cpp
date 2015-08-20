/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 1000

int arr[SIZE] = { 0 };
int visited[SIZE][SIZE] = { 0 };
int n, max;
int cnt;

int check(int ary[], int pos)
{
	int i, j, k;
	int flag, flag_cmp;
	int sum, temp;

	for (i = pos; i <= n - 1; i++)
	{
		sum = ary[i] + ary[i + 1];

		if (sum > max) // 합이 max 보다 크다면 fail
			return 0;

		// 교체
		temp = ary[i];
		ary[i] = ary[i + 1];
		ary[i + 1] = temp;

		flag = 1;
		for (j = 1; j <= cnt; j++) // 중복된 값인지를 판별
		{
			flag_cmp = 0;
			for (k = 1; k <= n; k++) // 중복체크
			{
				//printf("ary[%d] : %d / visited[%d][%d] : %d\n", k, ary[k], j, k, visited[j][k]);
				if (ary[k] == visited[j][k])
				{
					flag_cmp++; 
				}
			}
			if (flag_cmp == n){ // 중복 발생
				//printf("checked\n");
				// 교체
				temp = ary[i];
				ary[i] = ary[i + 1];
				ary[i + 1] = temp;

				flag = 0;
				break; // 중복되었으므로 넘어감
			}
		}
		return flag;
	}
}

void swap(int ary[])
{
	int temp;
	int i,j;

	for (i = 1; i <= n-1; i++)
	{
		if (check(ary, i)) // 넣어도 되는지를 판별
		{
			// 배열에 삽입
			cnt++;
			printf("%d -> ", cnt);
			for (j = 1; j <= n; j++)
			{
				visited[cnt][j] = ary[j];
				printf("%d", visited[cnt][j]);
			}
			printf("\n");

			swap(ary);
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

		int i;

		scanf("%d %d", &n, &max);

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		cnt = 1;
		for (i = 1; i <= n; i++)
		{
			visited[cnt][i] = arr[i];
		}
		swap(arr);
		
		printf("%d", cnt);
		printf("\n");
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}