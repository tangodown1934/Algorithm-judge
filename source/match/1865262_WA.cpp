#include <iostream>
using namespace std;
#define SIZE 50

typedef struct stack {
	int top;
	int data[SIZE];
};

void stack_push(stack *s, int data);
int stack_pop(stack *s);
bool stack_empty(stack *s);

int main() {
	int i,index=0;
	char arr[SIZE];
	int res[SIZE][2];
	stack s = {-1};

	cin >> arr;

	for(i=0; arr[i]!='\0'; i++) {
		if(arr[i]=='(') {
			stack_push(&s, i);
		}
		else if(arr[i]==')') {
			res[index][0] = stack_pop(&s);
			res[index++][1] = i;
		}
	}
	if(stack_empty(&s)) {
		for(i=0; i<index; i++)
			cout << res[i][0] << " " << res[i][1] << endl;
	}
	else
		cout << "not match";

	return 0;
}

void stack_push(stack *s, int data){
	if(s->top==SIZE-1) {
		return;
	}
	s->data[++s->top] = data;
}

int stack_pop(stack *s){
	int data;
	if(stack_empty(s))
		return -1;
	return s->data[(s->top)--];
}

bool stack_empty(stack *s) {
	if(s->top == -1)
		return true;
	return false;
}