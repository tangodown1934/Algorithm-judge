#include <stdio.h>
#pragma warning(disable:4996)

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{
		int n;
		int hi[90000];
		int sum = 0;
		int count = 0;
		int flag = 0;

		printf("#testcase%d\n", itr + 1);
		scanf("%d", &n);
		for (int i = 1; i < n + 1; i++){
			scanf("%d", &hi[i]);
		}

		for (int i = 1; i < n + 1; i++){
			sum = sum + count;
			flag = 0;
			count = 0;
			for (int j = i + 1; j < n+1; j++){
				if (hi[i] <= hi[j]){
					flag = 1;
					break;
				}
				if (hi[i] > hi[j] && flag == 0){
					count++;
				}
			}
		}

		printf("%d\n", sum);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}