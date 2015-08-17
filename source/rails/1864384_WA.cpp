#include <stdio.h>

int n_data[1111];

typedef struct stack
{
	int top;
	int data[1111];
};

void push(stack *st, int data)
{
	st->data[++st->top] = data;
}

void pop(stack *st)
{
	st->data[st->top--];
}

bool empty(stack *st)
{
	if (st->top == -1) return true;
	else return false;
}

int main()
{
	stack st;
	st.top = -1;
	int n;

	scanf("%d", &n);

	while(1)
	{
		int flag=0;

		for (int i = 0; i < n; i++)
		{
			scanf("%d", &n_data[i]);

			if (n_data[i] == 0)
			{
				flag = 2;
				break;
			}

			if (n_data[i] < n_data[i - 1] - 1)
			{
				if (i - 1 == 0 && n_data[0] == 1);
				else flag = 1;
			}
		}

		if (flag == 1) printf("NO\n");
		else if (flag == 2) break;
		else printf("YES\n");

	}

	return 0;
}