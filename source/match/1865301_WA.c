#include <stdio.h>

#define MAX_LEN 50

#define TRUE 1
#define FALSE 0

typedef struct _arraystack{
	char data[MAX_LEN];
	int numOfData;
}ArrayStack;

typedef ArrayStack Stack;

void InitStack(Stack* stack){
	stack->numOfData = -1;
}

void Push(Stack* stack, char data){
	stack->data[++stack->numOfData] = data;
}

int Pop(Stack* stack){
	int rmData;

	if (stack->numOfData < 0)
		return -1;

	rmData = stack->data[stack->numOfData--];

	return rmData;
}

int IsEmpty(Stack stack){
	if (stack.numOfData < 0)
		return TRUE;

	return FALSE;
}

int main(void){

	char inArr[MAX_LEN];
	char temp;
	int leftIdx[MAX_LEN];
	int rightIdx[MAX_LEN];
	int length=0;
	int i=0,j=0,k=0,l=0;

	scanf("%s",inArr);
	
	for (i=0; i<MAX_LEN; i++){
		if (inArr[i] == '\0'){
			break;
		}

		length++;
	}

	for (i=0; i<length; i++){
		if (inArr[i] == '(')
			leftIdx[j++] = i;

		else if(inArr[i] == ')'){
			rightIdx[k++] = i;
		}

		if (k>j){
			printf("not match\n");
			return 0;
		}
			
	}

	if (j==k){
		for (i=0,l=k-1;i<j;i++,l--){
			printf("%d %d \n",leftIdx[l],rightIdx[i]);
		}
	}

	else
		printf("not match \n");	

	return 0;
}