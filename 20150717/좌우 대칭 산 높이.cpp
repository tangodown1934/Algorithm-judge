/*

VC, GCC에서 사용

*/

#include <stdio.h>

void mont(int n)
{
	if (n == 1){
		printf("1");
		return;
	}

	mont(n - 1);
	printf("%d", n);
	mont(n - 1);
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int n;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &n);
		mont(n);
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}