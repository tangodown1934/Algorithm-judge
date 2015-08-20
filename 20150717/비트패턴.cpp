/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 40

int arr[SIZE] = { 0 };
int n, k;

void bit(int idx, int cnt)
{
	if (idx == n){
		if (cnt == k){
			for (int i = 0; i < n; i++)
			{
				printf("%d", arr[i]);
			}
			printf("\n");
		}

		return;
	}

	if (cnt <= k){
		arr[idx] = 1;
		bit(idx + 1, cnt+1);
		arr[idx] = 0;
		bit(idx+1, cnt);
	}
}
int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);
		scanf("%d %d", &n, &k);
		bit(0,0);
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}