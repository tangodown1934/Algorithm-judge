#include <stdio.h>

#define SIZE 1000

int arr[SIZE][SIZE];

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	int line, bomb;
	int x, y;
	int i, j;
	int cnt;

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr < nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		cnt = 0;

		scanf("%d %d", &line, &bomb);

		for (i = 0; i < line; i++){
			for (j = 0; j < line; j++){
				scanf("%d", &arr[i][j]);
			}
		}
		scanf("%d %d", &x, &y);

		while (cnt < line*line - bomb)
		{

		}
			

		/*

		�˰����� ���� �κ�

		*/

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}