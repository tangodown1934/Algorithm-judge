#include <stdio.h>

// n ����� ���� �� �ִ� ���� ��
int upstair(int n)
{
	if (!n) return 1;
	else if (n < 0) return 0;

	int ret = upstair(n - 1) + upstair(n - 2);

	return ret;
}

int main()
{
	int n;
	scanf("%d", &n);
	printf("%d\n", upstair(n));
	return 0;
} 
