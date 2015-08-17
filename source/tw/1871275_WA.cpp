#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int N;
	int arr[555555];
	int stack[555555];
	int temp[555555];
	int top = -1;
	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	stack[++top] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--){
		int count = 0;
		if (stack[top] > arr[i]){
			while (stack[top] > arr[i]){	
			    count++;
				if (stack[top] < arr[i - count]){
					temp[i + 1] = i - count + 1;
					break;
				}
				if (i == 0){
					temp[i + 1] = 0;
					temp[i] = 0;
					break;
				}
			}
			stack[++top] = arr[i];
		}
		else if (stack[top] < arr[i]){
			temp[i + 1] = i + 1;
			stack[++top] = arr[i];
		}
	}

	for (int i = 0; i < N;i++) printf("%d ", temp[i]);
	printf("\n");
	return 0;
}