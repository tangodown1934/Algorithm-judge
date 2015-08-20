/*

VC, GCC���� ���

*/

#include <stdio.h>

#define SIZE 1000

int arr[SIZE] = { 0 };
int visited[SIZE][SIZE] = { 0 };
int n, max;
int cnt;

int check(int ary[], int pos)
{
	int i, j, k;
	int flag, flag_cmp;
	int sum, temp;

	for (i = pos; i <= n - 1; i++)
	{
		sum = ary[i] + ary[i + 1];

		if (sum > max) // ���� max ���� ũ�ٸ� fail
			return 0;

		// ��ü
		temp = ary[i];
		ary[i] = ary[i + 1];
		ary[i + 1] = temp;

		flag = 1;
		for (j = 1; j <= cnt; j++) // �ߺ��� �������� �Ǻ�
		{
			flag_cmp = 0;
			for (k = 1; k <= n; k++) // �ߺ�üũ
			{
				//printf("ary[%d] : %d / visited[%d][%d] : %d\n", k, ary[k], j, k, visited[j][k]);
				if (ary[k] == visited[j][k])
				{
					flag_cmp++; 
				}
			}
			if (flag_cmp == n){ // �ߺ� �߻�
				//printf("checked\n");
				// ��ü
				temp = ary[i];
				ary[i] = ary[i + 1];
				ary[i + 1] = temp;

				flag = 0;
				break; // �ߺ��Ǿ����Ƿ� �Ѿ
			}
		}
		return flag;
	}
}

void swap(int ary[])
{
	int temp;
	int i,j;

	for (i = 1; i <= n-1; i++)
	{
		if (check(ary, i)) // �־ �Ǵ����� �Ǻ�
		{
			// �迭�� ����
			cnt++;
			printf("%d -> ", cnt);
			for (j = 1; j <= n; j++)
			{
				visited[cnt][j] = ary[j];
				printf("%d", visited[cnt][j]);
			}
			printf("\n");

			swap(ary);
		}
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

		for (i = 1; i <= n; i++)
		{
			scanf("%d", &arr[i]);
		}

		cnt = 1;
		for (i = 1; i <= n; i++)
		{
			visited[cnt][i] = arr[i];
		}
		swap(arr);
		
		printf("%d", cnt);
		printf("\n");
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}