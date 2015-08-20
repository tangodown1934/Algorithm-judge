#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111

char chr[SIZE];
int in[SIZE][SIZE];
int inCnt[SIZE];
int N, M;

int main()
{
	int itr, nCount;

	int i, j;
	int charCnt;
	int totalCnt;
	int flag;
	int temp;

	scanf("%d", &nCount);

	for (itr = 0; itr<nCount; itr++)
	{
		printf("#testcase%d\n", itr + 1);

		scanf("%s %d %d", chr,&N,&M);

		charCnt = totalCnt = 0;
		flag = 1;
		for (i = 0; chr[i] != '\0'; i++)
		{
			if (charCnt > 4)
			{
				flag = 0;
				break;
			}

			if (chr[i] >= 48 && chr[i] <= 57)
			{
				in[totalCnt][charCnt] = chr[i] - 48;
				charCnt++;
				inCnt[totalCnt] = charCnt;
			}
			else if (chr[i] == '-')
			{
				totalCnt++;
				charCnt = 0;
			}
			else{
				flag = 0;
				break;
			}
		}

		if (flag == 0){
			printf("INPUT ERROR!");
		}
		else{

			for (i = 0; i < 4 - inCnt[M - 1]; i++)
			{
				printf("%d", 0 + N);
			}

			for (i = 0; i < inCnt[M - 1]; i++)
			{
				temp = in[M - 1][i] + N;
				if (temp > 9)
				{
					temp = temp - (temp / 10) * 10;
				}
				printf("%d", temp);
			}
		}
		printf("\n");
	}
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}