#pragma warning(disable:4996)
#include <stdio.h>

#define MAX 1111
#define SIZE 22

int num[SIZE];
int check[MAX] = { 0, };

int main()
{
	int i;
	int cnt = 0;

	for (i = 0; i < 10; i++){
		scanf("%d", &num[i]);
		check[num[i] % 42] = 1;
	}

	for (i = 0; i < 1111; i++)
	{
		if (check[i])
			cnt++;
	}
	printf("%d\n", cnt);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}