#include <stdio.h>
#include <string.h>
//match
//20150713

#define SIZE 50
#define INIT -1

typedef char element;

typedef struct stack{
	int top;
	element data[SIZE];
	int index[SIZE];
};


void push(stack* st, element data, int index){
	if (st->top == SIZE - 1)
	{
		//printf("Stack is full\n");
		return;
	}

	st->data[++st->top] = data;
	st->index[st->top] = index;
	//printf("%c\n", data);

}

element pop(stack *st)
{
	//printf("%c\n", st->data[st->top]);
	return st->data[st->top--];
}

bool empty(stack *st){
	if (st->top < 0)	return true;
	else return false;
}

element Top(stack *st)
{
	return st->data[st->top];
}


int Top_index(stack *st)
{
	return st->index[st->top];
}

int main(){
	
	char str[100 + 1] = { 0 };
	int len = 0, ok = 1;
	stack opers,alpa;
	char val = 0;
	int index;
	opers.top = -1;
	alpa.top = -1;
	scanf("%s", str);
	len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		switch (str[i]){
		case '(':
			push(&opers, str[i], i);
			break;
		case '*':
			push(&opers, str[i], i);
			break;
		case '/':
			push(&opers, str[i], i);
			break;
		case '+':
			push(&opers, str[i], i);
			break;
		case '-':
			push(&opers, str[i], i);
			break;
		case ')':
			/*
			for(int j=0;j<=opers.top;j++){
				printf("%c ", opers.data[j]);
			}
			printf("\n");
			for(int j=0;j<=opers.top;j++){
				printf("%d ", opers.index[j]);
			}
			printf("\n");
			for(int j=0;j<=alpa.top;j++){
				printf("%c ", alpa.data[j]);
			}
			printf("\n");
			*/
			index = Top_index(&opers);
			
			while ( Top(&opers) != '('){
				pop(&opers);
				if (val != 0){
					val = pop(&alpa);
				}
				else{
					val = pop(&alpa);
					val = pop(&alpa);
				}

				if (opers.top < 0){
					ok = 0;
					printf("not match\n");
					break;
				}
			}
			if (ok != 1)	break;
			printf("%d %d\n", Top_index(&opers), i);
			pop(&opers);
			break;
		default : 
			push(&alpa, str[i],i);
			break;
		}
		if (ok != 1)	break;
	}

	return 0;
}