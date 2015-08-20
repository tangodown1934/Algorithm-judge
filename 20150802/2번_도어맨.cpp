#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111

int X;
char line[SIZE];
int  visited[SIZE];
int N;
int max;

int abs(int a)
{
	if (a < 0)
		return a *= -1;
	return a;
}

void sol(int i, int m, int w)
{
	int sum = m + w;

	// �������
	if (abs(m - w) > X) // �����̰� ����� �� �ִ� ���� ū ���̺��� ũ�ٸ� ����
		return;
	if (i == N + 1) 
		return;

	if (max < sum) // �Ź� �ִ밪 ���
		max = sum;

	if (visited[i] == 0){
		visited[i] = 1; // ���� ���� ���ϴ� ���
		if (line[i] == 'M')
			sol(i + 1, m + 1, w);
		else
			sol(i + 1, m, w+1);
	}

	if (visited[i + 1] == 0){ // ���� ���� ���ϴ� ���
		visited[i + 1] = 1;
		if (line[i + 1] == 'M')
			sol(i+1, m + 1, w);
		else
			sol(i+1, m, w + 1);
	}
}

int str_len(char str[])
{
	int cnt = 0;
	while (str[++cnt] != '\0'){}
	return cnt;
}

int main()
{
	scanf("%d", &X);

	scanf("%s", line);
	
	// init
	max = 0;
	N = str_len(line);
	for (int i = 0; i < N; i++)
		visited[i] = 0;

	sol(0, 0, 0);

	printf("%d\n", max);

	return 0;
}
