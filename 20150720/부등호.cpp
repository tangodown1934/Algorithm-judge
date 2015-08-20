#include <stdio.h>

#define SIZE 100

char cmp[SIZE];
int arr[SIZE];
int visited[22];

int n;

void dfs(int idx, int before)
{
	int i;

	if (idx == n)
	{
		printf("\n");
		for (i = 0; i < n + 1; i++)
		{
			printf("%d ", arr[i]);
		}
	}

	for (i = 0; i <= 9; i++)
	{ 
		if (visited[i] == 1) // 방문했다면 무시
			continue;

		if (idx == 0)
		{

		}

		switch (cmp[idx])
		{
		case '>': // 이전값보다 작아야함
			if (before > i) 
			{
				arr[idx] = i;
				visited[i] = 1; // 방문
				dfs(idx + 1, i); // 다음 괄호로
				visited[i] = 0; // 방문
			}
			break;
		case '<': // 이전 값보다 커야함 
			if (before < i)
			{
				arr[idx] = i;
				visited[i] = 1; // 방문
				dfs(idx + 1, i ); // 다음 괄호로
				visited[i] = 0; // 방문
			}
			break;
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


		scanf("%d\n", &n); // 부등호 개수 입력
		gets(cmp); // 부등호 입력

		//init
		for (i = 0; i <22; i++){ visited[i] = 0; }

		dfs(0, 0); // search
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}