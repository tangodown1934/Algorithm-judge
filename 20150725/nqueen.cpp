#include <stdio.h>
#pragma warning (disable:4996)

#define SIZE 22

int rows[SIZE];
int N;
int cnt;

int abs(int n)
{
	if (n < 0) return -n;
	return n;
}

int is_safe(int col, int k)
{
	int i;

	if (k == 0) // 최초로 넣은 경우 
		return 1;

	for (i = 0; i < k; i++) {
		if (rows[i] == col || abs(rows[i]-col) == abs(i-k)) // 같은 열을 가지면 안됨 || 열1-열2 == 행1-행2 => 대각선
			return 0;
	}

	return 1;
}

void queen(int k)
{
	int col;
	for (col = 0; col < N; ++col) 
	{
		if (is_safe(col, k)) // 유망한가 ?
		{
			rows[k] = col;

			if (k == N - 1) // 기저사례
			{ 
				cnt++;
				return;
			}
			
			queen(k + 1);
		}
	}
}

int main()
{
	scanf("%d", &N);

	cnt = 0;
	queen(0);
	printf("%d\n", cnt);

	return 0;
}