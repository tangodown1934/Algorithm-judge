#pragma warning(disable:4996)
#include <stdio.h>

#define NMAX 333333

typedef struct goosle{
	int pos;
	int dir;
}goosle;

int M, N, K;
goosle goo[NMAX];

void q_sort(goosle goo[], int left, int right)
{
	int l = left;
	int r = right;
	int pivot = goo[(left + right) / 2].pos;
	
	goosle temp;

	do{
		while (pivot < goo[l].pos) l++;
		while (pivot > goo[r].pos) r--;

		if (l <= r){
			temp = goo[l];
			goo[l] = goo[r];
			goo[r] = temp;
			l++; r--;
		}
	} while (l < r);

	if (left < r) q_sort(goo, left, r);
	if (right>l) q_sort(goo, l, right);
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
		int time, idx;
		int cnt;

		cnt = time = 0;
		scanf("%d %d %d", &M, &N, &K);

		for (i = 1; i <= N; i++)
		{
			scanf("%d %d", &goo[i].pos, &goo[i].dir);
		}

		q_sort(goo, 1, N);

		idx = goo[K].pos; // ������ġ�� ���� �� �ִ�

		for (i = 1; i <= N; i++) // �ð��� ����
		{
			if (goo[i].dir == 1){ // ���������� ���� ��츸
				cnt++;
			}
			if (cnt == K){
				time = M - goo[i].pos; // ������� - �ش� ���� ��ġ
				break;
			}
		}

		printf("%d %d\n", time, idx);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}