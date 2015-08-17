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

	//printf("r: %d val : %d time: %d front : %d \n", r, st.val, st.time, front);
}

void pop(){


	cheak[queue[front].val] = 1;
	front++;
	//printf("pop !!!front: %d \n", front);
}
int main()
{


	int itr;
	int nCount;		/* 문제의 테스트 케이스 */
	int a; int b;
	int pv;
	int pt;

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)

	{


		front = 0;
		r = -1;

		scanf("%d %d", &a, &b);

		printf("#testcase%d\n", itr + 1);


		P0L q;
		q.val = a;
		q.time = 0;
		push(q);






		while (queue[front].val != b){


			if (cheak[queue[front].val] != 1) {


				pv = queue[front].val;
				pt = queue[front].time;

				//printf("pv: %d, pt: %d \n", pv, pt);
				P0L st;

				if (cheak[pv - 1] != 1 && pv - 1 <= b && pv<100000 && pv>0)
				{
					st.val = queue[front].val - 1;
					st.time = pt + 1;
					push(st);

				}

				if (cheak[pv + 1] != 1 && pv + 1 <= b && pv<100000 && pv>0)
				{
					st.val = queue[front].val + 1;
					st.time = pt + 1;
					push(st);

				}

				if (cheak[pv * 2] != 1 && pv * 2 <= b && pv<100000 && pv>0)
				{
					st.val = queue[front].val * 2;
					st.time = pt + 1;
					push(st);

				}



				pop();


			}
		}






		printf("%d\n", queue[front].time);

	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}