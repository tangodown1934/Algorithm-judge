#include <stdio.h>

int hi[80000 + 1] = { 0 };
int hi_cnt[80000 + 1] = { 0 };

#define SIZE 80000 + 1

typedef int element;

typedef struct stack{
	int top;
	
	element data[SIZE];
	element index[SIZE];
};

void push(stack* st, element data,int index){
	if (st->top == SIZE - 1)
	{
		printf("Stack is full\n");
		return;
	}

	st->data[++st->top] = data;
	st->index[st->top] = index;
	//printf("%d\n", data);

}

int pop(stack *st)
{
	//printf("%d\n", st->data[st->top]);
	return st->data[st->top--];
}

bool empty(stack *st){
	if (st->top < 0)	return true;
	else return false;
}

int Top(stack *st)
{
	return st->data[st->top];
}

int Top_index(stack *st)
{
	return st->index[st->top];
}

stack min;

int main(){


	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	//for (itr = 0; itr<nCount; itr++)
	//{
		min.top = -1;
		//printf("#testcase%d\n", itr + 1);
		int N, sum = 0;
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &hi[i]);
		}

		for (int i = 0; i < N; i++)
		{
			
			if (!empty(&min)){
				if (hi[i] < Top(&min)){
					//현재값이 이전값보다 작을때
					push(&min, hi[i], i);
				}
				else{
					while ( min.top > 0 && (hi[i] > Top(&min) ) ){
						//현재값이 이전값보다 클때까지
						sum += i - Top_index(&min);
						pop(&min); 
						//printf("%d top : %d hi[i] : %d min : %d\n", sum, min.top, hi[i], min.data[min.top]);
						
					}
					//현재값이 이전값보다 작거나 같을때
					if (!empty(&min) && (Top(&min) <= hi[i]) ){
						pop(&min);
						push(&min, hi[i], i);
					}
					else{
						//현재값이 이전값보다 작을