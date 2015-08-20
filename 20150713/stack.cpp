#include <stdio.h>
#include <string.h>

typedef struct stack{
	int top;
	int data[50];
};

void push(stack *st, int data)
{
	if(st->top == 49)
	{
		return;
	}
	
	st->data[++st->top] = data;
}
int pop(stack *st)
{
	return st->data[st->top--];
}
int empty(stack *st)
{
	if(st->top < 0) return 1;
	else return 0;
}
int top(stack *st)
{
	return st->data[st->top];
}	
int main()
{
	stack st;
	int i;
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	char ch[50];
	int count;	

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
	
		st.top = -1;
		count = 0;

		scanf("%s", ch);
		for(i=0;i < strlen(ch); i++)
		{
			if(ch[i] == '(')
				count++;
			else if(ch[i] == ')')
				count--;
		}

		if(count!=0)
		{
			printf("not match\n");
		}else{
			for(i=0;i < strlen(ch); i++)
			{
				if(ch[i] == '(')
				{
					push(&st, i);
				}else if(ch[i] == ')'){
					if(!empty(&st))
					{
						printf("%d %d\n", pop(&st), i);
					}
				}
			}
		}

	}
	return 0;
}