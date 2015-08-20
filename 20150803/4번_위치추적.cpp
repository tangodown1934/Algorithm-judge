#pragma warning(disable:4996)
#include <stdio.h>

#define NMAX 111111
#define MMAX 333333
#define STRMAX 111111

int N, M;

typedef struct elec{
	int x;
	int y;
}elec;

elec ele[NMAX]; // 통신설비
char str[STRMAX];

int abs(int n)
{
	if(n<0) return -n;
	return n;
}

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		int i,j;
		int len;
		int res;
		int x,y;

		scanf("%d %d", &N, &M);

		for(i=0;i<N;i++)
		{
			scanf("%d %d", &ele[i].x, &ele[i].y);
		}
		
		scanf("%s", &str);
		
		x = y = 0;
		for(i=0;str[i]!='\0';i++)
		{
			switch(str[i])
			{
			case 'W':
				x -= 1;
				break;
			case 'N':
				y += 1;
				break;
			case 'E':
				x += 1;
				break;
			case 'S':
				y -= 1;
				break;
			}

			res = 0;
			for(j=0;j<N;j++)
			{
				res += abs(ele[j].x-x)+abs(ele[j].y-y);
			}
			printf("%d ", res);
		}
		printf("\n");
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}