#include <stdio.h>
#include <string.h>

#define SIZE 1000

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
	stack st;
	char ch[SIZE];
	
	int flag=0;
	int a[SIZE];
	int i, l=0;
	
	st.top = -1;
	
	scanf("%s", ch);
	for(i=0;i<strlen(ch);i++){
		if(ch[i]=='('){
			push(&st, i);
		}else if(ch[i]==')'){
			if(!empty(&st)){
				a[l++] = pop(&st);
				a[l++] = i;
			}else{
				flag=1;
			}
		}
	}
	if(flag==1 || !empty(&st)){
		printf("not match\n");
	}else{
		for(i=0;i<l;i+=2){
			printf("%d %d\n", a[i], a[i+1]);
		}
	}


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}