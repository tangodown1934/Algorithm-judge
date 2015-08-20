#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int n, m;
	int nCount;
	int i = 0;
	int ans1;
	int ans2;

	scanf("%d", &nCount);
	for (i = 1; i <= nCount; i++)
	{
		scanf("%d %d", &n, &m);
		ans1 = n / 6 * m / 6;
		ans2 = 0;

		if (n % 6 > 0) {
			ans2 = m / 6;
		}

		if (m % 6 > 0)
		{
			ans2 = n / 6;
		}

		if (m % 6 > 0 && n % 6 > 0)
		{
			ans2 = m / 6 + n / 6;
			ans2++;
		}
		printf("#%d %d %d", i, ans1, ans2);
		printf("\n");
	}
	return 1;
}