#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 77

int N, K;
int cnt;

int num[SIZE];

void sol(int idx, int sum)
{
	int i;

	if(idx==K)
	{
		if(sum==0)
		{
			cnt++;
			
		}
		return;
	}

	for(i=num[idx-1];i<=N;i++)
	{
		if((sum-i)<0) return;
		num[idx] = i;
		sol(idx+1, sum-i);
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

		scanf("%d %d", &N, &K);

		cnt = 0;
		
		for(i=1;i<N;i++)
		{
			num[0] = i;
			sol(1, N-i);
		}

		printf("%d\n", (cnt%1000000007));
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}