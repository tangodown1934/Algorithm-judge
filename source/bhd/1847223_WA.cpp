#include <stdio.h>

int N, cnt;
int arr[88888];

typedef struct stack{
	int top;
	int data[88888];
}stack;
void push(stack* st, int data)
{
	if (st->top == 888888)
	{
		printf("Stack is Full\n");
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

	for (int i = 0; i < N; i++)
	{
		push(&st, arr[i]);
		if (st.data[st.top-1] > arr[i])
		{
			cnt += st.top;
			pop(&st);
			
		}
	}

	printf("%d\n", cnt);

	return 0;
}