
#include <stdio.h>



typedef struct P0L
{
	int val;
	int time;

}POL;

int front;
int r;

void push(P0L st, POL * queue,int *cheak ){


	queue[++r] = st;
	cheak[st.val] = 1;
	//printf("r: %d val : %d time: %d front : %d \n", r, st.val, st.time, front);
}

void pop(){


	
	front++;
	
}
int main()
{


	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int a; int b;
	int pv;
	int pt;


	
		

		front = -1;
		r = -1;

		scanf("%d %d", &a, &b);

		POL queue[11111] = {};
		int cheak[11111] = {};

		




		if (a == b){

			printf("%d", 0);

		}
		else if (a > b)
		{
			printf("%d", a - b);

		}
		else{


			P0L q;
			q.val = a;
			q.time = 0;
			push(q,queue,cheak);

			while (queue[front].val != b && front <= r){



				


				pop();

				pv = queue[front].val;
				pt = queue[front].time;
				P0L st;


				if (cheak[pv - 1] != 1 && pv - 1 <= b&& pv-1<100000 && pv-1 >= 0)
				{
					st.val = pv - 1;
					st.time = pt + 1;
					push(st, queue, cheak);

				}

				if (cheak[pv + 1] != 1 && pv + 1 <= b && pv+1<100000 && pv+1 >= 0)
				{
					st.val = pv + 1;
					st.time = pt + 1;
					push(st, queue, cheak);

				}

				if (cheak[pv * 2] != 1 && pv * 2 <= b && pv*2<100000 && pv*2 >= 0)
				{
					st.val = pv * 2;
					st.time = pt + 1;
					push(st, queue, cheak);

				}


			}




			printf("%d", queue[front].time);


		}






	

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */


}

