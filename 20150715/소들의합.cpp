#include <stdio.h>

#define SIZE 100

typedef struct stack
{
	int top;
	int data[SIZE];
}stack;

void push(stack *st, int data)
{
	if(st->top == SIZE-1)
		return;

	st->data[++st->top] = data;
}

int pop(stack *st)
{
	return st->data[st->top--];
}

int empty(stack *st)
{
	if(st->top == -1)
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
	int nCount;		/* 문제의 테스트 케이스 */
	int num[SIZE], arr[SIZE];
	int count;
	stack st;
	int i,sum;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		sum=0;
		st.top=-1;

		scanf("%d", &count);

		for(i=0;i<count;i++){
			scanf("%d", &num[i]);
			arr[num[i]] = 0;
		}
		push(&st, num[count-1]);
		for(i=count-2;i>=0;i--){
			while(num[i] > top(&st) && !empty(&st))
			{
				arr[num[i]]++;
				pop(&st);
				sum += arr[i];
				sum ++;
			}
			push(&st, num[i]);
		}
		printf("%d", sum);
		printf("\n");
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}