/*

VC, GCC���� ���

*/

#include <stdio.h>

#define SIZE 1000

typedef struct stack{
	int top;
	int data[SIZE];
}stack;

void push(stack *st, int data)
{
	if (st->top == SIZE - 1)
	{
		return;
	}

	st->data[++st->top] = data;
}

void pop(stack *st)
{
	st->top--;
}

int top(stack *st)
{
	return st->data[st->top];
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	int count, i;
	int arr[SIZE];


	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		stack st;
		st.top = -1;

		scanf("%d", &count);
		for (i = 0; i < count; i++){
			scanf("%1d", &arr[i]);

			if (top(&st) == arr[i])
				pop(&st);
			else
				push(&st, arr[i]);
		}
		for (i = 0; i <= st.top; i++){
			printf("%d", st.data[i]);
		}

		printf("\n");
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */

}