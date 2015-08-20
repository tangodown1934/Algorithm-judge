#pragma warning(disable:4996)
#include <stdio.h>

/*
제일 중요한 2가지
1. pop 연산하기 이전에 무조건 empty인지 확인 하고 pop
2. 배열의 사이즈
*/

#define SIZE 555555

int START, DES;
int visited[SIZE];

typedef struct q
{
	int data[SIZE];
	int time[SIZE];
	int front;
	int rear;
}q;

q queue;

void push(q *queue, int data, int time)
{
	if (queue->front - 1 == queue->rear == 1)
	{
		printf("Queue is full");
		return;
	}
	queue->data[queue->rear] = data;
	queue->time[queue->rear] = time;
	queue->rear = (queue->rear + 1) % SIZE;
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
		return 1;
	}
	return 0;
}
int front(q *queue)
{
	return queue->data[queue->front];
}
int main()
{
	int nCount;
	int i, n;
	int time;
	int temp, front;

	scanf("%d %d", &START, &DES);

	// Initialize
	for (i = 0; i < SIZE; i++)
	{
		visited[i] = 0;
	}

	time = queue.front = queue.rear = 0;
	push(&queue, START, time);
	visited[START] = 1;
	while (!empty(&queue))
	{
		front = queue.data[queue.front];
		time = queue.time[queue.front];

		if (front == DES){
			printf("%d\n", time);
			break;
		}

		time++;
		temp = front - 1;
		if (temp > 0 && temp <= DES && visited[temp] == 0){
			push(&queue, temp, time);
			visited[temp] = 1;
		}
		temp = front + 1;
		if (temp > 0 && temp <= DES && visited[temp] == 0){
			push(&queue, temp, time);
			visited[temp] = 1;
		}
		temp = front * 2;
		if (temp > 0 && temp <= DES && visited[temp] == 0){
			push(&queue, temp, time);
			visited[temp] = 1;
		}

		pop(&queue);
	}
	return 1;
}
