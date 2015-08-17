#include <stdio.h>

unsigned int N, index;
int arr[888888];

typedef struct stack{
	int top;
	int data[888888];
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
	stack st2;
	st.top = -1;
	st2.top = -1;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
	{
		scanf("%d", &arr[i]);
	}

	push(&st, arr[0]);
	push(&st2, 1);
	index = 1;
	printf("0 ");

	for (int i = 1; i < N; i++)
	{
		while (Top(&st) < arr[i])
		{
			pop(&st);
			pop(&st2);
			if (empty(&st)) break;
		}
		if (empty(&st))
		{
			printf("0 ");
			push(&st, arr[i]);
			push(&st2, i + 1);
		}
		else
		{
			printf("%d ", st2.data[st2.top]);
			push(&st, arr[i]);
			push(&st2, i + 1);
		}
	}
	printf("\n");
	return 0;
}