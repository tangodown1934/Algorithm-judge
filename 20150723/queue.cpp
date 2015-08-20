#include <stdio.h>

/*
	���� �߿��� 2����
	1. pop �����ϱ� ������ ������ empty���� Ȯ�� �ϰ� pop
	2. �迭�� ������ 

*/

#define SIZE 10000

typedef struct q
{
	int data[SIZE];
	int front;
	int rear;
}q;

void push(q *queue, int data)
{
	if (queue->front - 1 == queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->data[queue->rear++] = data;
	queue->rear %= SIZE;
}

void pop(q *queue)
{
	queue->front++;
	queue->front %= SIZE;
}

int empty(q *queue)
{
	if (queue->front == queue->rear)
	{
		return 0;
	}
	return 1;
}