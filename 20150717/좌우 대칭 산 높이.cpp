/*

VC, GCC���� ���

*/

#include <stdio.h>

void mont(int n)
{
	if (n == 1){
		printf("1");
		return;
	}

	mont(n - 1);
	printf("%d", n);
	mont(n - 1);
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	int n;

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &n);
		mont(n);
		printf("\n");
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}