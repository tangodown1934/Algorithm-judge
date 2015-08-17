#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int N;
int arr[555555];
int stack[555555];
int temp[555555];
int top = -1;

int main()
{

	//freopen("1.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
	}
	stack[++top] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--){
		if (arr[i] > stack[top]){
			stack[top] = arr[i];
			temp[i + 1] = i + 1;
			while (1){
				if (top == 0){
					break;
				}
				if (stack[top] > stack[top - 1]){
					temp[i + top + 1] = i + 1;
					top--;
					stack[top] = arr[i];					
				}
				else{
					break;
				}
			}
		}
		else{
			stack[++top] = arr[i];
		}
	}
	
	for (int i = 0; i < N;i++) printf("%d ", temp[i]);
	printf("\n");

	return 0;
}


