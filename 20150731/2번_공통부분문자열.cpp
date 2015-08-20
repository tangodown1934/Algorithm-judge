#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 4444

char a[SIZE];
char b[SIZE];

int dp[SIZE][SIZE];
int row;
int a_count;
int b_count;

int strLength(char str[]) // ���ڿ� ����
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

		// DP - �ڱ��ڽ��� �˻��ϴ� ���� �ƴ� ������ ���ٸ� �� ������ ���
		max = 0;
		for (i = 1; i<=a_count; i++){ // ���������� ����ؾ��ϹǷ� �⺻ �迭 �������� +1 
			for (j = 1; j<=b_count; j++){ // ���������� ����ؾ��ϹǷ� �⺻ �迭 �������� +1 
				if (a[i - 1] == b[j - 1]){ // ���� ���� ���ٸ� ������ ���
					dp[i][j] = dp[i - 1][j - 1] + 1; // �������������
					
					if (max < dp[i][j]) // �ִ� ������ ���
						max = dp[i][j];
				}
			}
		}
		printf("%d\n", max); // �����...
	}
	return 0;
}