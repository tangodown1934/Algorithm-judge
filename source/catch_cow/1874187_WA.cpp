#include <stdio.h>
#define SIZE 111111
//int visited[SIZE];

typedef struct queue{
	int front;
	int rear;
	int data[SIZE]; 
};

void push(queue* q,int data)
{ 
	if (q->front - q->rear == 1 || q->front - q->rear == -(SIZE - 1)){
		printf("FULL\n");
		return;
	}
	//printf("push: %d\n",data);
	q->data[q->rear++] = data;
	q->rear = q->rear % SIZE;
}

int pop(queue* q)
{
	if (q->rear == q->front) return -1;

	int data = q->data[q->front++];
	q->front = q->front % SIZE;
	return data;
}

bool empty(queue* q){
	if(q->front == q->rear) return true;
	else return false;
}
int main()
{
	//int itr;
	//int nCount;	

	//scanf("%d", &nCount);

	//for(itr=0; itr<nCount; itr++)
	//{


	int s_point;
	long e_point;
	scanf("%d %d",&s_point,&e_point);

	bool visited[SIZE]={};
	queue q;
	q.front=0;q.rear=0;
	push(&q,s_point);

	queue t;
	t.front=0;t.rear=0;
	push(&t,0);

	int time=0;
	int num=0;

	while(num!=e_point){

		num =pop(&q);
		time =pop(&t);
		if(num==e_point) break;

		if(visited[num-1]==0  && num<SIZE){
			push(&q,num-1);
			push(&t,time+1);
			visited[num-1]=1;
		}
		if (num < e_point) {
			if(visited[num+1]==0 && num<SIZE){
				push(&q,num+1);
				push(&t,time+1);
				visited[num+1]=1;
			}

			if(visited[num*2]==0 && num<SIZE){
				push(&q,num*2);
				push(&t,time+1);
				visited[num*2]=1;
			}
		}


	}
	//printf("#testcase%d\n",itr+1);
	printf("%d\n",time);
	//}

	return 0;

}