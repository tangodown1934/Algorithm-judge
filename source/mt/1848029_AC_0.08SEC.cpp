#include <stdio.h>
int num;
// n ����� ���� �� �ִ� ���� ��
int mountain(int n)
{
	if (n == 1)
	{
		printf("\n");
		return 0;
	}

	if (num < n)
	{
		printf("%d", ++num);
		mountain(n);
	}
	else
	{
		printf("%d", n-1);	
		mountain(n - 1);
	}
}

int main()
{
	int n;
	scanf("%d", &n);

	mountain(n);

	return 0;
} 
