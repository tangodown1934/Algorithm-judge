#include <stdio.h>
#include <stdlib.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		
		int police_x, thief_x;
		scanf("%d %d",&police_x,&thief_x);
	
		int queue[600000];
		int queue_time[600000];
		int isVisit[400000]={0};
		int front=-1;
		int rear=-1;
		queue[++rear]=police_x;
		queue_time[rear]=0;
		front++;
		while(front<=rear) {
			police_x=queue[front%600000];
			if(police_x==thief_x) break;
			if(0==isVisit[police_x-1]) {
				queue[++rear%600000]=police_x-1;
				isVisit[police_x-1]=1;
				queue_time[rear%600000]=queue_time[front%900000]+1;
			}
			if(0==isVisit[police_x+1]) {
				queue[++rear%600000]=police_x+1;
				isVisit[police_x+1]=1;
				queue_time[rear]=queue_time[front%600000]+1;
			}
			if(police_x*2<300000&&0==isVisit[police_x*2]) {
				queue[++rear%600000]=police_x*2;
				isVisit[police_x*2]=1;
				queue_time[rear%600000]=queue_time[front%900000]+1;
			}
			front++;
		}

		printf("%d\n",queue_time[front%600000]);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
