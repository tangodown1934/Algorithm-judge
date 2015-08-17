#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

		int width, height;
		scanf("%d %d",&height,&width);
		
		int maze[20][20]={0};
		for(int i=0;i<height;i++) {
			for(int j=0;j<width;j++) {
				int tmp;
				scanf("%1d",&tmp);
				maze[i][j]=tmp;
			}
		}
	
		if(1==maze[height-1][0]||1==maze[0][width-1]) {
			printf("-1\n");
			return 0;
		}

		int queue_x[10000]={0};
		int queue_y[10000]={0};
		int queue_time[10000]={0};
		int front=-1;
		int rear=-1;
		queue_x[++rear]=0;
		queue_y[rear]=height-1;
		queue_time[rear]=1;
		maze[height-1][0]=1;
		front++;
		while(front<=rear){
			int x=queue_x[front];
			int y=queue_y[front];
			if(y==0&&x==width-1) break;
		
			if(y-1>=0&&0==maze[y-1][x]) {
				rear++;
				queue_x[rear]=x;
				queue_y[rear]=y-1;
				queue_time[rear]=queue_time[front]+1;
				maze[y-1][x]=1;
			}
			if(x+1<width&&0==maze[y][x+1]) {
				rear++;
				queue_x[rear]=x+1;
				queue_y[rear]=y;
				queue_time[rear]=queue_time[front]+1;
				maze[y][x+1]=1;
			}
			if(y+1<width&&0==maze[y+1][x]) {
				rear++;
				queue_x[rear]=x;
				queue_y[rear]=y+1;
				queue_time[rear]=queue_time[front]+1;
				maze[y+1][x]=1;
			}
			if(x-1>=0&&0==maze[y][x-1]) {
				rear++;
				queue_x[rear]=x-1;
				queue_y[rear]=y;
				queue_time[rear]=queue_time[front]+1;
				maze[y][x-1]=1;
			}
			front++;
		}
		if(front>rear) {
			printf("-1\n");
		} else {	
			printf("%d\n",queue_time[front]);
		}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
