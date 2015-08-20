#include <stdio.h>

#define SIZE 100

char cmp[SIZE];
int arr[SIZE];
int visited[22];

int n;

void dfs(int idx, int before)
{
	int i;

	if (idx == n)
	{
		printf("\n");
		for (i = 0; i < n + 1; i++)
		{
			printf("%d ", arr[i]);
		}
	}

	for (i = 0; i <= 9; i++)
	{ 
		if (visited[i] == 1) // �湮�ߴٸ� ����
			continue;

		if (idx == 0)
		{

		}

		switch (cmp[idx])
		{
		case '>': // ���������� �۾ƾ���
			if (before > i) 
			{
				arr[idx] = i;
				visited[i] = 1; // �湮
				dfs(idx + 1, i); // ���� ��ȣ��
				visited[i] = 0; // �湮
			}
			break;
		case '<': // ���� ������ Ŀ���� 
			if (before < i)
			{
				arr[idx] = i;
				visited[i] = 1; // �湮
				dfs(idx + 1, i ); // ���� ��ȣ��
				visited[i] = 0; // �湮
			}
			break;
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


		scanf("%d\n", &n); // �ε�ȣ ���� �Է�
		gets(cmp); // �ε�ȣ �Է�

		//init
		for (i = 0; i <22; i++){ visited[i] = 0; }

		dfs(0, 0); // search
		printf("\n");
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}