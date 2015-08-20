#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 4444

char a[SIZE];
char b[SIZE];

int dp[SIZE][SIZE];
int row;
int a_count;
int b_count;

int strLength(char str[]) // 문자열 길이
{
	int cnt = 0;
	while (str[cnt++] != '\0'){}
	return cnt-1;
}
int main()
{
	int n, nCount;

	scanf("%d", &nCount);
	for (n = 0; n < nCount; n++)
	{
		int i,j;
		int max;

		scanf("%s\n%s", &a, &b);
		a_count = strLength(a); b_count = strLength(b);
		
		// Initialize
		for (i = 0; i<=a_count; i++)
			for (j = 0; j<=b_count; j++)
				dp[i][j] = 0;

		// DP - 자기자신을 검사하는 것이 아닌 이전에 같다면 그 개수를 기록
		max = 0;
		for (i = 1; i<=a_count; i++){ // 마지막까지 계산해야하므로 기본 배열 범위보다 +1 
			for (j = 1; j<=b_count; j++){ // 마지막까지 계산해야하므로 기본 배열 범위보다 +1 
				if (a[i - 1] == b[j - 1]){ // 이전 값이 같다면 개수를 기록
					dp[i][j] = dp[i - 1][j - 1] + 1; // 증가시켜줘버령
					
					if (max < dp[i][j]) // 최대 개수를 기록
						max = dp[i][j];
				}
			}
		}
		printf("%d\n", max); // 개어렵...
	}
	return 0;
}