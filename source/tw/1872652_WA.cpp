#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int N;
int arr[555555];
int stack[555555];
int temp[555555];
int top = 0;
int sum;

int main()
{

	//freopen("1.txt", "r", stdin);

	scanf("%d", &N);
	for (int i = 1; i <= N; i++){
		scanf("%d", &arr[i]);
	}

	stack[top] = arr[N];

	for (int i = N-1; i > 0; i--){
		if (stack[top] < arr[i]){
			//pop을 하고 
			temp[stack[top]] = i; //인덱스값 저장시키고
			stack[top] = arr[i]; //해당자리에 push하고
			while (1){
				if (top == 0) break;
				if (stack[top] > stack[top - 1]){
					temp[stack[--top]] = i; //인덱스값 저장시키고
					stack[top] = arr[i]; //해당자리에 push하고
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

	for (int i = 1; i <= N; i++) {
		printf("%d ", temp[arr[i]]);
	}
	printf("\n");
	return 0;
}