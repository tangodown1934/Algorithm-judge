/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 500000

int main()
{
	int arr[SIZE];
	int i_arr[SIZE];

	int i, j,n;
		
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	for (i = n-1; i >=0; i--)
	{
		i_arr[i] = 0;
		for (j = i - 1; j>0; j--)
		{
			if (arr[i] < arr[j]){
				i_arr[i] = j+1;
				break;
			}
		}
	}

	for (i = 0; i < n; i++){
		printf("%d ", i_arr[i]);
	}
	printf("\n");
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}