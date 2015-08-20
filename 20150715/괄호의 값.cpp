/*
-1 ����


*/
#include <stdio.h>
#include <string.h>

#define SIZE 60

typedef struct stack{
	int top;
	int data[SIZE];
}stack;

void push(stack *st, int data)
{
	if (st->top == SIZE - 1)
		return;

	st->data[++st->top] = data;
}

int pop(stack *st)
{
	return st->data[st->top--];
}

int empty(stack *st)
{
	if (st->top == -1)
		return 1;
	else
		return 0;
}

int top(stack *st)
{
	return st->data[st->top];
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

	char ch[SIZE];
	int i = 0;
	int count, sum, not_match;
	stack st;

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for (itr = 0; itr < nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%s", ch);
		st.top = -1;
		not_match = 0;
		count = 0;
		for (i = 0; i<strlen(ch); i++)
		{
			sum = 0;
			if (not_match)
				break;
			switch (ch[i]){
			case '(':
				push(&st, -2);
				break;
			case '[':
				push(&st, -3);
				break;
			case ')':
				if (top(&st) > 0) // �ڿ����� �ִ� ���
				{
					while (top(&st) > 0)
					{
						sum += pop(&st);
					}
					if (top(&st) == -2)
					{
						pop(&st);
						push(&st, sum * 2);
					}
					else{
						not_match = 1;
					}
				}
				else if (top(&st) == -2){ // �ڽ��� ��ȣ
					pop(&st);
					push(&st, 2);
				}
				else{
					not_match = 1;
				}
				break;
			case ']':
				if (top(&st) > 0) // �ڿ����� �ִ� ���
				{
					while (top(&st) > 0)
					{
						sum += pop(&st);
					}
					if (top(&st) == -3)
					{
						pop(&st);
						push(&st, sum * 3);
					}
					else{
						not_match = 1;
					}
				}
				else if (top(&st) == -3){
					pop(&st);
					push(&st, 3);
				}
				else{
					not_match = 1;
				}
				break;
			}
		}
		if (not_match == 0){
			while (!empty(&st))
			{
				count += pop(&st);
			}
			printf("%d", count);
		}
		else{
			printf("not match");
		}
		printf("\n");
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */
}