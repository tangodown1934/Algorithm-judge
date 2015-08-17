/*

VC, GCC에서 사용

*/

#include <stdio.h>
#pragma warning(disable:4996)

int main()
{


		int N;
		int K;
		int time = 1;
		int queue[999999];
		int queueIndex = 0;
		int front = 0;
		int rear = 1;
		int temp[999999] = { 0 };
		scanf("%d %d", &N, &K);
		queue[0] = N;
		temp[N] = 1;
        if (N == K){
           printf("0\n");
	    }
	    else if (N > K){
		   printf("%d\n", N - K);
	    }
		else{
			for (int i = front; i < rear; i++){

				if (queue[i] == 0){
					queue[++queueIndex] = queue[i] - 1;  
				}
				else if (temp[queue[i] - 1] == 0){
					queue[++queueIndex] = queue[i] - 1;  
					temp[queue[i] - 1] = 1;
				}

				if (queue[i] == 0){
					queue[++queueIndex] = queue[i] + 1;  
				}
				else if (queue[i] == 0 || temp[queue[i] + 1] == 0){
					queue[++queueIndex] = queue[i] + 1;  
					temp[queue[i] + 1] = 1;
				}

				if ((queue[i] * 2) <= 100000){
					if (temp[queue[i] * 2] == 0){
						queue[++queueIndex] = queue[i] * 2;  
						temp[queue[i] * 2] = 1;
					}
				}
				if (queue[i] - 1 == K || queue[i] + 1 == K || queue[i] * 2 == K){
					printf("%d\n", time);
					break;
				}

				if (i == rear - 1){
					front = rear;
					rear = queueIndex + 1;
					time++;
				}
			}
		}


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}