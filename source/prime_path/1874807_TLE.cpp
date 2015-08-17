#include <stdio.h>

#define SIZE 111111

typedef struct queue{
	int head;
	int tail;
	int data[SIZE];	
}queue;

queue q;
int step[SIZE] = { 0 };

void push(queue *q, int data)
{
	if ((q->tail + 1) % SIZE == q->head)
		return;

	q->data[q->tail] = data;

	//printf("%d\n", q->data[q->tail]);

	q->tail = (q->tail + 1) % SIZE;
}

int pop(queue *q)
{
	if (q->tail == q->head)
		return 0;

	int temp = q->data[q->head];

	q->head = (q->head + 1) % SIZE;

	return temp;
}

int head(queue *q)
{
	return q->data[q->head];
}

int isPrime(int n)
{
	for (int i = 2; i < n;i++){
		if (n%i == 0)
			return 0;
	}
	return 1;
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
		int i, j, n, m;
		int temp;
		int pos;
		int flag;

		q.head = q.tail = 0;
		flag = 1;
		scanf("%d %d", &start, &dest);
		
		if (start == dest){
			printf("0\n");
			continue;
		}
			
		for (i = 0; i < SIZE; i++){ step[i] = 0; }

		push(&q, start);
		while (flag)
		{
			m = 1; // 1의 자리부터 시작
			start = head(&q);
			if (start < 0){
				pop(&q);
				continue;
			}
			for (i = 0; i < 4; i++)
			{
				if (flag==0)
					break;

				for (j = 0; j < 10; j++)
				{
					pos = (start / m) % 10; // 현재 자리수 를 구함
					if (pos != j) // 현재 자리수의 값은 생각할 필요가 없다
					{
						if (j == 0 && m == 1000) continue;

						temp = start - pos*m;
						temp += j*m;

						if (isPrime(temp))
						{
							// 소수이고 도착수라면 step[]+1 종료
							if (temp == dest)
							{
								// printf("temp : %d/ step : %d\n", temp, step[head(&q)]);
								step[dest] = step[head(&q)] + 1;
								flag = 0;
								break;
							}
							else{
								// 소수이고 도착수 아니면 꼬리에 push
								if (step[temp] == 0){
									push(&q, temp);
									step[temp] = step[head(&q)] + 1;
								}
							}
						}
					}
				}
				m *= 10; // 점점 올라감
			}
			pop(&q);  // 다음으로 넘어감
		}
		printf("%d", step[dest]);
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}
