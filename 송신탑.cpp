/*

VC, GCC���� ���

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 555555

int arr[SIZE] = { 0 };
int arrTop[SIZE];
int st[SIZE];
int st_pos[SIZE];

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */


	int top;
	int n;
	int i;

	scanf("%d", &n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &arr[i]);
		arrTop[i] = 0;
	}

	top = 1;

	st[top] = arr[n];
	st_pos[top] = n;

	for (i = n - 1; i >= 1; i--)
	{
		while (arr[i] > st[top] && top > 0)
		{
			arrTop[st_pos[top]] = i; // ��� 
			top--;
		}
		++top;
		st[top] = arr[i];
		st_pos[top] = i;
	}

	for (i = 1; i <= n; i++)
	{
		printf("%d ", arrTop[i]);
	}

	printf("\n");

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}