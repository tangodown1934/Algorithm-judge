#include <stdio.h>

#define SIZE 11111

typedef struct queue{
	int head;
	int tail;
	int count[SIZE];
	int time[SIZE];
}queue;

queue q;
int visited[SIZE] = { 0 };

void push(queue *q, int count, int time)
{
	if ((q->tail + 1) % SIZE == q->head)
		return;

	q->count[q->tail] = count;
	q->time[q->tail] = time;

	q->tail = (q->tail + 1) % SIZE;
}

int pop(queue *q)
{
	if (q->tail == q->head)
		return 0;

	int temp = q->count[q->head];

	q->head = (q->head + 1) % SIZE;

	return temp;
}

int head(queue *q)
{
	return q->count[q->head];
}

int main()
{
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		int start, dest;
		int time = 0;
		int cnt = 0;
		int mul = 3;
		int temp;
		q.head = q.tail = 0;

		scanf("%d %d", &start, &dest);

		if (start > dest){
			printf("%d", start - dest);
		}
		else{
			for (int i = 0; i < SIZE; i++) { visited[i] = 0; }

			push(&q, start, time);
			time++;
			while (1)
			{
				//printf("head : %d (time : %d) - %d\n", head(&q), q.time[q.head], q.head);
				start = head(&q);

				if (start+1 <= SIZE && visited[start + 1] != 1)
					push(&q, start + 1, time);
				if (start - 1 >= 0 && visited[start - 1] != 1)
					push(&q, start - 1, time);

				if (start * 2 <= SIZE && visited[start*2] != 1)
				{
					if (start < 0){
						push(&q, start * -1, time);
					}
					else{
						push(&q, start * 2, time);
					}
				}

				cnt++;
				if (cnt == mul){
					time++;
					mul *= 3;
					cnt = 0;
				}

				if (head(&q) == dest){
					printf("%d", q.time[q.head]);
					break;
				}
				else{
					visited[pop(&q)] = 1;
				}
			}
		}
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}
