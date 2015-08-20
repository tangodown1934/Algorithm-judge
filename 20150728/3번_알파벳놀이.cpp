#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 22
#define COUNT 30

char str[SIZE];
int cnt[COUNT];

int strCnt;

void sol(int idx, int cnt[], char str[])
{
	int i;

	if (idx == strCnt)
	{
		str[idx] = '\0';
		printf("%s\n", str);
		return;
	}

	for (i = 0; i < 30; i++)
	{
		if (cnt[i]>0)
		{
			str[idx] = i + 'a';
			cnt[i]--;
			sol(idx + 1, cnt, str);
			cnt[i]++;
		}
	}
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	int i;
	char printStr[SIZE];

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%s", &str);

		for (i = 0; i < COUNT; i++)
		{
			cnt[i] = 0;
		}

		// init
		strCnt = 0;
		for (i = 0; str[i] != '\0'; i++)
		{
			cnt[str[i] - 'a']++;
			strCnt++;
		}

		sol(0, cnt, printStr);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}