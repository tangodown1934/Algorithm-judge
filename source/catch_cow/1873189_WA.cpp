#include <stdio.h>
#include <stdlib.h>

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */


		int police_x, thief_x;
		scanf("%d %d",&police_x,&thief_x);
	
		int queue[9000000];
		int queue_time[9000000];
		int isVisit[300000]={0};
		int front=-1;
		int rear=-1;
		queue[++rear]=police_x;
		queue_time[rear]=0;
		front++;
		while(front<=rear) {
			police_x=queue[front];
			if(police_x==thief_x) break;
			if(0==isVisit[police_x-1]) {
				queue[++rear]=police_x-1;
				isVisit[police_x-1]=1;
				queue_time[rear]=queue_time[front]+1;
			}
			if(0==isVisit[police_x+1]) {
				queue[++rear]=police_x+1;
				isVisit[police_x+1]=1;
				queue_time[rear]=queue_time[front]+1;
			}
			if(0==isVisit[police_x*2]) {
				queue[++rear]=police_x*2;
				isVisit[police_x*2]=1;
				queue_time[rear]=queue_time[front]+1;
			}
			front++;
		}

		printf("%d\n",queue_time[front]);


	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}
