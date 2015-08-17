#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{

	//int itr;
	//int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	//for (itr = 0; itr<nCount; itr++)
	//{
		int n;
		int k;
		int queue[999999];
		int temp[999999] = { 0 };
		int queueIndex = 0;
		int count = 0;
		int front = 0;
		int rear = 1;
		//printf("#testcase%d\n", itr + 1);
		scanf("%d %d", &n, &k);
		queue[0] = n;
		if (n > k){
			printf("%d\n", n-k);
		}
		else{
			for (int i = front; i < rear; i++){
				if (temp[queue[i] - 1] == 0 || i == 0){
					queue[++queueIndex] = queue[i] - 1;
					temp[queue[i] - 1] = 1;
				}
				if (temp[queue[i] + 1] == 0 || i == 0){
					queue[++queueIndex] = queue[i] + 1;
					temp[queue[i] + 1] = 1;
				}

				if (queue[i] * 2 <= 100000){
					if (temp[queue[i] * 2] == 0 || i == 0){
						queue[++queueIndex] = queue[i] * 2;
						temp[queue[i] * 2] = 1;
					}
				}

				if ((queue[i] - 1) == k || (queue[i] + 1) == k || (queue[i] * 2) == k){
					if (i == rear - 1){
						printf("%d\n", count + 1);
					}
					else{
						printf("%d\n", count);
					}
					break;
				}
				if (i == rear - 1){
					front = rear;
					rear = queueIndex;
					count++;
				}
			}
		}

	//}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}