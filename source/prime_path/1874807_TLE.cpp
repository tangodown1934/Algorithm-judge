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
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

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
			m = 1; // 1�� �ڸ����� ����
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
					pos = (start / m) % 10; // ���� �ڸ��� �� ����
					if (pos != j) // ���� �ڸ����� ���� ������ �ʿ䰡 ����
					{
						if (j == 0 && m == 1000) continue;

						temp = start - pos*m;
						temp += j*m;

						if (isPrime(temp))
						{
							// �Ҽ��̰� ��������� step[]+1 ����
							if (temp == dest)
							{
								// printf("temp : %d/ step : %d\n", temp, step[head(&q)]);
								step[dest] = step[head(&q)] + 1;
								flag = 0;
								break;
							}
							else{
								// �Ҽ��̰� ������ �ƴϸ� ������ push
								if (step[temp] == 0){
									push(&q, temp);
									step[temp] = step[head(&q)] + 1;
								}
							}
						}
					}
				}
				m *= 10; // ���� �ö�
			}
			pop(&q);  // �������� �Ѿ
		}
		printf("%d", step[dest]);
		printf("\n");
	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}
