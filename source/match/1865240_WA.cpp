#include<stdio.h>
#define stack_size 55
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
}

int pop(stack *st){
	return st->data[st->top--];
}

bool empty(stack* st){
	if(st->top<0) return true;
	else return false;
}

int Top(stack *st){
	return st->data[st->top];
}


int main(){
	stack st;
	st.top=-1;

	char string[50];
	gets(string);
	
	int i=0;
	while(string[i]!=NULL){
		if(string[i]=='('){
			push(&st,i);
		}else if(string[i]==')'){
			if(!empty(&st)) printf("%d ",pop(&st));
			printf("%d\n",i);
		}
		i++;
	}

	if(!empty(&st)) printf("not match");
	return 0;
}