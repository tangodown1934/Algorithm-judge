/*

VC, GCC���� ���

*/

#include <stdio.h>

#define SIZE 1111

int arr[SIZE] = { 0 };
int visited[SIZE] = { 0 };
int n, max;

void change(int idx)
{
	if (idx == n)
	{
		
		return;
	}

	for (int i = 0; i < n; i++)
	{

	}
}
int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int i;

		scanf("%d %d", &n, &max);
		
		for (i = 0; i < n; i++)
		{
			scanf("%d", &arr[i]);
		}

		for (i = 0; i < max; i++)
		{
			visited[i] = 0;
		}

		change(1);
		printf("\n");
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}