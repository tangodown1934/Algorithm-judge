#include <stdio.h>
#include <stdlib.h>

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */

		double count=0;

		int stack[90000];
		int top=0;
		int number_cows;
		scanf("%d",&number_cows);
		int *cows;
		cows = (int *)malloc(number_cows*sizeof(int));
		int number_watchable_cows=0;
		for(int i=0;i<number_cows;i++) {
			int new_cow;
			scanf("%d",&new_cow);
			while(stack[top-1]<=new_cow) {
				if(top==0) break;
				top--;
			}
			count+=top;
			stack[top++]=new_cow;
		}
		printf("%d",count);
	

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}
