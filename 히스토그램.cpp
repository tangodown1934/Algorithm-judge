/*

VC, GCC���� ���

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

#define SIZE 111111

int arr[SIZE] = { 0 };

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */


	int n;
	int i;
	int temp, max;

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}

	max = 1;

	for (i = 0; i < n - 1; i++)
	{
		if (arr[i] <= arr[i + 1])
		{
			temp = arr[i] * 2;
		}
		else{
			temp = arr[i + 1] * 2;
		}
		if (max < temp)
			max = temp;
	}

	printf("%d", max);

	printf("\n");

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}