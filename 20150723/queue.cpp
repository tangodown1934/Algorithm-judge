#include <stdio.h>

/*
	제일 중요한 2가지
	1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
	2. 배열의 사이즈 

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