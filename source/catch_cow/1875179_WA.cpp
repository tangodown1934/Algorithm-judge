
#include <stdio.h>



typedef struct P0L
{
	int val;
	int time;

}POL;


POL queue[111111];
int cheak[111111];
int front;
int r;

void push(P0L st){

	
	queue[++r] = st;

}

void pop(){

	
	cheak[queue[front].val] = 1;
	front++;
}
int main()
{


	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int a; int b;
	int pv;
	int pt;




		front = 0;
		r = -1;

		scanf("%d %d", &a, &b);



		if(a==b){
		
		printf("%d", 0);
		
		}
		
		else if (a > b)
		{
			printf("%d", a-b);

		}
		else{


			P0L q;
			q.val = a;
			q.time = 0;
			push(q);

			while (queue[front].val != b && front <= r){





				pv = queue[front].val;
				pt = queue[front].time;
				P0L st;
                
                pop();
                
                
				if (cheak[pv - 1] != 1 && pv - 1 <= b&& pv<100000 && pv>=0)
				{
					st.val = pv- 1;
					st.time = pt + 1;
					push(st);

				}

				if (cheak[pv + 1] != 1 && pv + 1 <= b && pv<100000 && pv>=0)
				{
					st.val = pv+1;
					st.time = pt + 1;
					push(st);

				}

				if (cheak[pv * 2] != 1 && pv * 2 <= b && pv<100000 && pv>=0)
				{
					st.val = pv*2;
					st.time = pt + 1;
					push(st);

				}



				


			}




			printf("%d", queue[front].time);


		}
		
	


		
	
	

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */


}
