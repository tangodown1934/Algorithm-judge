/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>

#define SIZE 100
#define LEN 70

typedef struct stack{
	int top;
	char* data[SIZE];
};

void push(stack *st, char *data)
{
	if(st->top == SIZE-1)
	{
		return;
	}
	
	char temp[LEN] = data;

	st->data[++st->top] = temp;
}
char* pop(stack *st)
{
	return st->data[st->top--];
}
int empty(stack *st)
{
	if(st->top < 0) return 1;
	else return 0;
}
char* top(stack *st)
{
	return st->data[st->top];
}
void flush(stack *st)
{
	st->top = -1;
}

int main()
{
	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	stack back, forward;
	char *inst, input[LEN];
	char token[100], *url="https://secmem.org", *load_url;
	

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{
		printf("#testcase%d\n",itr+1);

		back.top = forward.top = -1;
		
		while(1){
			scanf("\n");
			gets(input);
			
			inst = strtok(input, " ");
			load_url =	strtok(NULL, " ");

			if(strcmp(inst, "VISIT")==0){
				push(&back, url); // 현재 페이지를 저장
				url = load_url; // 현재 페이지를 수정 
				flush(&forward); // 비워버림
			}else if(strcmp(inst, "BACK")==0){
				printf("BACK");
				if(!empty(&back)){
					push(&forward, url);
					url = pop(&back);
				}else{
					printf("Ignored\n");
				}
			}else if(strcmp(inst, "FORWARD")==0){
				if(!empty(&forward)){
					push(&back, url);
					url = pop(&forward);
				}else{
					printf("Ignored\n");
				}
			}else if(strcmp(inst, "QUIT")==0){
				break;
			}
			printf("url : %s\n", url);
			printf("load_url : %s\n", load_url);
		}
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}