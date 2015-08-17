#include <stdio.h>

#define TRUE 1
#define FALSE 0

#define STACK_SIZE 80000

typedef int Data;

typedef struct _arraystack{
	Data data[STACK_SIZE];
	int numOfData;
}ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack* stack){
	stack->numOfData = -1;
}

void Push(Stack* stack, Data data){
	stack->data[++stack->numOfData] = data;
}

Data Pop(Stack* stack){
	int remData;

	remData = stack->data[stack->numOfData--];

	return remData;
}

int IsEmpty(Stack* stack){
	if (stack->numOfData == -1)
		return TRUE;

	return FALSE;
}

Data Seek(Stack* stack){
	if (stack->numOfData == -1)
		return -1;
	return stack->data[stack->numOfData];
}

unsigned int Alg(int cows[STACK_SIZE], int numOfCow){

	int i,j;
	int count[STACK_SIZE]={0};
	int tempCount=0, sum=0;
	int idx;
	Stack stack;

	StackInit(&stack);

	Push(&stack,numOfCow-1);
	count[numOfCow-1] = 0;

	for (i=numOfCow-2; i>=0; i--){

		while((!IsEmpty(&stack))&&(cows[i] > cows[Seek(&stack)])){
			idx = Pop(&stack);
			count[i] += (count[idx]+1);
			sum += (count[idx]+1);
		}	
		Push(&stack,i);
	}

	return sum;
}

int main()
{
	int i;
	unsigned int result;
	int numOfCows;
	int cows[STACK_SIZE];

	


	scanf("%d",&numOfCows);
	for (i=0; i<numOfCows; i++){
		scanf("%d",&cows[i]);
	}

	result = Alg(cows,numOfCows);
	printf("%u\n",result);


	return 0;
}