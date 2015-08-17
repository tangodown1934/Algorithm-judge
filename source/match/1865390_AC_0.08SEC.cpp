#include<stdio.h>
#define stack_size 55
int result[55]={};

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

	char string[55];
	gets(string);
	
	int i=0;
	int cnt=0;
	int top=0;
	while(string[i]!=NULL){
		if(string[i]=='('){
			push(&st,i);
		}else if(string[i]==')'){
			if(!empty(&st)){
				result[cnt]=pop(&st);
				cnt++;
				result[cnt]=i;
				cnt++;
			}else{
				result[0]=1000;
			}
		}
		i++;
	}

	if(!empty(&st) || result[0]==1000) printf("not match");
	else{
		for(int i=0;i<cnt-1;i+=2){
			printf("%d %d\n",result[i],result[i+1]);
		}
	}
	return 0;
}