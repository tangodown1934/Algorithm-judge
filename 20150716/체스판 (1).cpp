#include <stdio.h>

#define SIZE 1000

int arr[SIZE][SIZE];

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int line, bomb;
	int x, y;
	int i, j;
	int cnt;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

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

		알고리즘이 들어가는 부분

		*/

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}