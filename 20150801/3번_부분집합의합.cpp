#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 22

int N, S;
int num[SIZE];
int visited[SIZE];
int cnt;

void sol(int i, int sum)
{
	if (i == N) // ±âÀú»ç·Ê
	{
		if (sum == S)
			cnt++;
		return;
	}

	if (!visited[i])
	{
		visited[i] = 1;
		sol(i + 1, sum + num[i]);
		visited[i] = 0;
		sol(i + 1, sum);
	}
}
int main()
{
	int i;

	scanf("%d %d", &N, &S);
	for (i = 0; i < N; i++){
		scanf("%d", &num[i]);
		visited[i] = 0;
	}
	cnt = 0;
	for (i = 0; i < N; i++)
	{
		visited[i] = 1;
		sol(i + 1, num[i]);
	}
	printf("%d\n", cnt);
	return 0;
}
