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
		int stackIndex = -1;
		int sum = 0;
		int tempIndex;
		scanf("%d",&n);
		for (int i = 0; i < n; i++){
			scanf("%d", &arr[i]);
		}

		for (int i =n-1; i >= 0; i--){
			if (stackIndex == -1){
				stack[++stackIndex] = arr[i];
			}
			else{
				if (stack[stackIndex]<arr[i]){
					stack[++stackIndex] = arr[i];
					tempIndex = stackIndex;
					while (1){
						if (tempIndex == 0){
							break;
						}
						if (arr[i] > stack[--tempIndex]){
							sum++;
						}
						else{
							break;
						}
					}
				}
				else{
					stack[++stackIndex] = arr[i];
				}
			}
		}
		
		printf("%d\n", sum);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}
