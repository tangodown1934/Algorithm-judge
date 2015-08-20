#pragma warning(disable:4996)
#include <stdio.h>


int main()
{
	int n, nCount;

	scanf("%d", &nCount);
	for (n = 0; n < nCount; n++)
	{
		int a, b;
		int inc;
		int sum = 0;
		int temp;

		scanf("%d %d", &a, &b);


		inc = a;
		temp = inc;
		do{
			temp = inc;
			do{
				sum += (temp % 10);
				// printf("ÀÚ¸´¼ö : %d, sum : %d\n", temp % 10, sum);
				temp /= 10;
			} while (temp != 0);
			inc++;
		} while (inc != (b+1));

		printf("%d\n", sum);
	}
	return 0;
}