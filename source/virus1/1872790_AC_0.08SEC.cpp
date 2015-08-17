#include <stdio.h>

typedef struct _network{
	int top;
	int linked[200];
}Network;


int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */


		int number_of_computers;
		scanf("%d",&number_of_computers);

		int number_of_links;
		scanf("%d",&number_of_links);
	
		Network network[200];
		for(int i=0;i<200;i++) {
			network[i].top=-1;
		}
		for(int i=0;i<number_of_links;i++) {
			int from,to;
			scanf("%d %d",&from,&to);
	
			network[from].linked[++network[from].top]=to;
			network[to].linked[++network[to].top]=from;
		}
		int queue[200]={0};
		int front=-1;
		int rear=-1;
		queue[++rear]=1;
		front++;
		for(int i=1;front<=rear;i=queue[++front]) {
			while(-1!=network[i].top) {
				int ing=0;
				int computer = network[i].linked[network[i].top--];
				for(int j=0;j<=rear;j++) {
					if(queue[j]==computer) ing=1; // already infected
				}
				if(0==ing) {
					queue[++rear]=computer;
				}
			}
		}

		printf("%d\n",rear);


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
