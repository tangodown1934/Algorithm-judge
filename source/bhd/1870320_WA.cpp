/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{


		int hieght;
		int n;
		int arr[90000];
		int stack[90000];
		int stackIndex = 0;
		int sum = 0;
		scanf("%d", &n);
		for (int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}

		stack[stackIndex] = n - 1;
		for (int i = n - 2; i >= 0; i--){	
			if (stack[stackIndex] > arr[i]){
				stack[++stackIndex] = arr[i];
			}
			else{
				while (stack[stackIndex] < arr[i]){
					--stackIndex;
					sum++;
				}
				stack[stackIndex] = arr[i];
			}
		}
		printf("%d\n", sum);
	


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}