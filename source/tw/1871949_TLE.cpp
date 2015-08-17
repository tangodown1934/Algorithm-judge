#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int N;
int arr[555555];
int stack[555555];
int temp[555555];
int indexArr[99999999];
int top = -1;


int main()
{

	//freopen("1.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 0; i < N; i++){
		scanf("%d", &arr[i]);
		indexArr[arr[i]] = i + 1;
	}
	stack[++top] = arr[N - 1];
	for (int i = N - 2; i >= 0; i--){
		if (arr[i] > stack[top]){
			while (1){
				if (arr[i] > stack[top]){
					temp[indexArr[stack[top]] - 1] = indexArr[arr[i]];
					stack[top] = arr[i];
					top--;
					if (top < 0) { top++; break; }
				}
			}
		}
		else{
			top++;
			stack[top] = arr[i];
		}
	}
	
	for (int i = 0; i < N;i++) printf("%d ", temp[i]);

	return 0;
}

