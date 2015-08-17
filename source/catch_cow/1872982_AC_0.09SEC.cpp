#define _CRT_SECURE_NO_WARNINGS

/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define TRUE 1
#define FALSE 0

typedef struct __step_t {
	int x;
	int time;
} step_t;

int visit[100001];
step_t queue[1000000];

int main()
{


		int i, time, police, robber;
		int not_finish = TRUE;
		int front = -1, rear = -1;

		for (i = 0; i <= 100000; i++) visit[i] = FALSE;


		scanf("%d %d", &police, &robber);

		// push
		queue[++rear].x = police;
		queue[rear].time = 0;
		visit[police] = TRUE;

		while (not_finish) {
			// pop
			// printf("step : %d\n", queue[front + 1].x);
//			if (queue[front + 1].x < 0) continue;
			police = queue[++front].x;
			time = queue[front].time + 1;
			if (police == robber) {
				time -= 1;
				not_finish = FALSE;
				break;
			}
//			printf("pop : %d\n", police);

			// push
			if (police + 1 <= 100000 && visit[police + 1] == FALSE) {
//				printf("%d\t", police + 1);
				queue[++rear].x = police + 1;
				queue[rear].time = time;
				visit[police + 1] = TRUE;
				if (police + 1 == robber) {
//					printf("%d\n", time);
					not_finish = FALSE;
					break;
				}
			}

			// push
			if (police - 1 >= 0 && visit[police - 1] == FALSE) {
//				printf("%d\t", police - 1);
				queue[++rear].x = police - 1;
				queue[rear].time = time;
				visit[police - 1] = TRUE;
				if (police - 1 == robber) {
//					printf("%d\n", time);
					not_finish = FALSE;
					break;
				}
			}

			//push
			if (police * 2 <= 100000 && visit[police * 2] == FALSE) {
//				printf("%d\t", police*2);
				queue[++rear].x = police * 2;
				queue[rear].time = time;
				visit[police * 2] = TRUE;
				if (police * 2 == robber) {
//					printf("%d\n", time);
					not_finish = FALSE;
					break;
				}
			}
//			printf("\n");
		}

		printf("%d\n", time);
		return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}