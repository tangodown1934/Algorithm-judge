#include <stdio.h>
#define stack_size 88888
int result[88888];

typedef struct stack{
	int top;
	int data[stack_size];
};

void push(stack* st,int data){
	if(st->top==stack_size-1){
		printf("Stack is full\n");
		return;
	}

	st->data[++(st->top)] =data;
	//printf("%d\n",data);
}

int pop(stack *st){
	//printf("pop:%d\n",st->data[st->top]);
	return st->data[st->top--];
}

bool empty(stack* st){

	if(st->top<0) return true;
	else return false;
}

int Top(stack *st){
	return st->data[st->top];
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	//scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	//for(itr=0; itr<nCount; itr++)
	//{
		int n;
		scanf("%d",&n);
		
		int cows[stack_size];

		for(int i=0;i<n;i++){
			scanf("%d",&cows[i]);
		}
		stack st;
		st.top=-1;

		//맨왼쪽
		push(&st,cows[n-1]);
		result[n]=0;
		int sum=0;
		int pop_cnt=0;
		//
		for(int i=n-2;i>-1;i--){
			
			int ex = st.data[st.top];
			//printf("ex: %d\n",ex);
			result[ex]=pop_cnt;
			pop_cnt=0;

			while(st.top>-1 && cows[i]>st.data[st.top]){
				if(pop_cnt==1){
					printf("가중치 (result[%d]): %d \n",st.data[st.top],result[st.data[st.top]]);
					pop_cnt+=result[st.data[st.top]];
				}
				pop(&st);
				pop_cnt++;
			}
			
			//printf("pop_cnt: %d\n",pop_cnt);
			push(&st,cows[i]);
			sum+=pop_cnt;
		}
		//printf("#testcase%d\n",itr+1);
		printf("%d\n",sum);

	//}

	return 0;

}