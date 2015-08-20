#pragma warning(disable:4996)
#include <stdio.h>

int N;

int main()
{
	int i;
	int cnt;
	int itr;
	int temp;
	int flag;

	scanf("%d", &N);

	cnt = 1;
	itr = 666;
	temp = itr;

	while (1)
	{
		if (cnt == N)
			break;

		itr++;
		temp = itr;

		flag = 0;
		do{
			if ((temp % 10) == 6){ // 6이 연속으로 세번 나올경우
				flag++;

				if (flag == 3){
					cnt++;
					break;
				}
			}
			else{
				flag = 0;
			}

			temp /= 10;
		} while (temp != 0);
	}

	printf("%d\n", itr);

	return 0;
}