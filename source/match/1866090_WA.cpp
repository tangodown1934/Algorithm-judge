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

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

		char *input;
		int stack[100];
		scanf("%s",input);
		int err=0;
		for(int i=0;i<51;i++) {
			if('('==input[i]) {
				push(stack,i);
			} else if (')'==input[i]) {
				int tmp=pop(stack);
				if(-1==tmp) {
					err=1;
					break;
				} else {
				}
			}
		}
		
		if(0==err&&-1!=top) {
			err=1;
		}	
		if(0==err) {
			for(int i=0;i<51;i++) {
				if('('==input[i]) {
					push(stack,i);
				} else if(')'==input[i]) {
					printf("%d %d\n",pop(stack),i);
				}
			}
		 } else {
			printf("not match\n");		
		 }

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
