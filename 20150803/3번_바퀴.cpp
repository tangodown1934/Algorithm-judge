#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 1111111

char str1[SIZE];
char str2[SIZE];
int num1[SIZE];
int num2[SIZE];

// int hex[][SIZE] = { { 0, 0, 0, 0 }, { 0, 0, 0, 1 }, { 0, 0, 1, 0 }, { 0, 0, 1, 1 }, { 0, 1, 0, 0, }, { 0, 1, 0, 1 }, { 0, 1, 1, 0 }, { 0, 1, 1, 1 },{ };

int hex[22][10];

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	int num = 1;

	printf("%d", num<<1);

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int i,j;

		scanf("%s %s", &str1, &str2);
		
		

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}