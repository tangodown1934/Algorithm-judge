#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{

	//int itr;
	//int nCount;		/* ������ �׽�Ʈ ���̽� */

	//scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	/*for (itr = 0; itr<nCount; itr++)
	{*/
		int N;
		int arr[90000];
		int stack[90000];
		int temp[90000] = { 0 };
		int top = 0;
		int sum = 0;
		//printf("#testcase%d\n", itr + 1);

		scanf("%d", &N);
		for (int i = 1; i <= N; i++){
			scanf("%d", &arr[i]);
		}

		stack[top] = arr[N];

		for (int i = N - 1; i > 0; i--){
			int count = 0;
			if (stack[top] < arr[i]){
				//pop
				stack[top] = arr[i];
				++count;
				temp[stack[top]] = temp[stack[top]]+count;
				while (1){
					if (top == 0) break;
					if (stack[top] > stack[top - 1]){
						//pop
						stack[--top] = arr[i];
						++count;
						temp[stack[top]] = temp[stack[top]] + count;
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

		for (int i = 1; i <= N; i++){
			sum = sum + temp[arr[i]];
		}
		printf("%d\n",sum);

	//}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}



