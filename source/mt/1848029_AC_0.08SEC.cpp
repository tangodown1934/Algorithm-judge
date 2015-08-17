#include <stdio.h>
int num;
// n 계단을 오를 수 있는 가짓 수
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
