/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>

#define SIZE 100

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	int x, y;
	char arr[SIZE][SIZE], f_arr[SIZE];
	char temp;
	int i, j;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int l = 0;
		int count = 0;

		scanf("%d %d", &x, &y);
		for (i = 0; i < y; i++)
		{
			scanf("%s", &arr[i]);
		}

		for (i = 0; i < y; i++)
		{
			for (j = 0; j < x; j++)
			{
				l = 0;
				if ((arr[i][j] != 'f' || arr[i][j] != 'a' || arr[i][j] != 'c' || arr[i][j] != 'e') &&
					(arr[i][j+1] != 'f' || arr[i][j+1] != 'a' || arr[i][j+1] != 'c' || arr[i][j+1] != 'e') &&
					(arr[i+1][j] != 'f' || arr[i+1][j] != 'a' || arr[i+1][j] != 'c' || arr[i+1][j] != 'e') &&
					(arr[i + 1][j + 1] != 'f' || arr[i + 1][j + 1] != 'a' || arr[i + 1][j + 1] != 'c' || arr[i + 1][j + 1] != 'e')){

					f_arr[l++] = arr[i][j];
					f_arr[l++] = arr[i][j + 1];
					f_arr[l++] = arr[i + 1][j + 1];
					f_arr[l++] = arr[i + 1][j];
					f_arr[4] = '\0';
				}
				if (l == 4){
					for (int m = 0; m < 4; m++){
						for (int n = 0; n < 3; n++){
							if (f_arr[n] > f_arr[n + 1])
							{
								temp = f_arr[n + 1];
								f_arr[n + 1] = f_arr[n];
								f_arr[n] = temp;
							}
						}
					}
					if (strcmp(f_arr, "acef") == 0){
						count++;
						//printf("(%d,%d)\n", i, j);
					}
				}
			}
		}
		printf("%d", count);
		printf("\n");
	}


	printf("\n");
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}