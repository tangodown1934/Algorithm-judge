#include <stdio.h>

unsigned int N, index;
int arr[88888];

typedef struct stack{
	int top;
	int data[88888];
}stack;
void push(stack* st, int data)
{
	if (st->top == 888888)
	{
		return;
	}

	st->data[++st->top] = data;
}
int pop(stack* st)
{
	return st->data[st->top--];
}
bool empty(stack* st)
{
	if (st->top < 0) return true;
	else return false;
}
int Top(stack* st)
{
	return st->data[st->top];
}

int main()
{
	stack st;
	st.top = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	push(&st, arr[0]);
	index = 1;
	printf("0 ");

	for (int i = 1; i < N; i++)
	{
		while (Top(&st) < arr[i])
		{
			pop(&st);
			index--;
			if (empty(&st)) break;
		}
		if (empty(&st))
		{
			printf("0 ");
			push(&st, arr[i]);
			index = i + 1;
		}
		else
		{
			printf("%d ", index);
			push(&st, arr[i]);
			index = i + 1;
		}
	}
	printf("\n");
	return 0;
}