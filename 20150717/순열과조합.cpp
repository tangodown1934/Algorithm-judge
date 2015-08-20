/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 30

int n, r, p, q;
int alpha[SIZE];
int visited[SIZE];
int cnt;
int sort_cnt;

void sort_count(int idx)
{
	if (idx == r)
	{
		sort_cnt++;
		
		if (sort_cnt == q)
		{
			for (int i = 0; i < r; i++){
				printf("%c", alpha[i] + 65);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < n; i++)	
	{
		if (visited[i] == 0){ // 방문 하지 않았다면
			visited[i] = 1;

			if (idx >= 1 && alpha[idx - 1] > i)
			{}
			else{
				alpha[idx] = i;
				sort_count(idx + 1);
			}

			visited[i] = 0;
		}
	}
}

void count(int idx)
{
	if (idx == r)
	{
		cnt++;

		if (cnt == p)
		{
			for (int i = 0; i < r; i++){
				printf("%c", alpha[i] + 65);
			}
			printf("\n");
		}
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (visited[i] == 0){ // 방문 하지 않았다면
			visited[i] = 1;
			alpha[idx] = i;
			count(idx + 1);

			visited[i] = 0;
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

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);

		sort_cnt = cnt = 0;
		for (int i = 0; i < n; i++){ visited[i] = 0; }
		count(0);
		for (int i = 0; i < n; i++){ visited[i] = 0; }
		sort_count(0);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}