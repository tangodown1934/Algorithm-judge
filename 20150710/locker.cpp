/*

VC, GCC���� ���

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	int n, k;
	int i, j, mul, temp;
	int locker[100];

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%d %d", &n, &k);
		
		for (i = 0; i < 100; i++){
			locker[i] = 1;
		}

		for (i = 2; i <= n; i++){
			j = i;
			mul = 1;
			temp = j*mul;
			while (temp-1 < 100){
				locker[temp-1] =  !locker[temp-1];
			    // printf("count i : %d / j : %d, mul : %d, locker[%d] : %d\n", i, j, mul, temp-1, temp);
				mul++;
				temp = j*mul;
			}	
			// printf("\n");
		}

		printf("%d\n", locker[k-1]);
	}

	// system("pause");

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}