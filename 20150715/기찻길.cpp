/*

VC, GCC에서 사용

*/

#include <stdio.h>

#define SIZE 10000

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
	
	int arr[SIZE];
	stack rail, st;
	int i,j;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		int count, temp;
		int l=0, flag=1;
		int cnt=1;

		rail.top = -1;
		scanf("%d", &count);
		for(i=0;i<count;i++){
			scanf("%d", &arr[i]);
		}

		for(i=0;i<count;i++){
			push(&rail, arr[i]);

			while(top(&rail) == cnt){
				cnt++;
				pop(&rail);
			}
		}

		if(empty(&rail))
			printf("Yes");
		else
			printf("No");
		
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}