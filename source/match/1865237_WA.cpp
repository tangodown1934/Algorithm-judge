#include <stdio.h>

int top = -1;
void push(int *stack, int num) {
	if(top>9999) return;
	stack[++top]=num;
}
int pop(int *stack) {
	if(top==-1) {
		return -1;
	} else {
		return stack[top--];
	}
} 
int main() {
	int stack[10000];
	char buffer[10000];
	scanf("%s",buffer);

	for(int i=0;buffer[i]!='\0';i++) {
		if('('==buffer[i]) {
			push(stack,i);
		} else if(')'==buffer[i]) {
			int result = pop(stack);
			if(-1==result) {
				printf("not match\n");
				return 0;
			}
		}
	}
	for(int i=0;buffer[i]!='\0';i++) {
		if('('==buffer[i]) {
			push(stack,i);
		} else if(')'==buffer[i]) {
			int result = pop(stack);
			printf("%d %d\n",result,i);
		}
	}
	return 0;
}
