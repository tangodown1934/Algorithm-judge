#include <stdio.h>
#include <stdlib.h>

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */


		int count=0;

		int number_cows;
		scanf("%d",&number_cows);
		int *cows;
		cows = (int *)malloc(number_cows*sizeof(int));
		int number_watchable_cows=0;
		for(int i=0;i<number_cows;i++) {
			int new_cow;
			scanf("%d",&new_cow);
			for(int j=0;j<number_watchable_cows;j++) {
				if(cows[j]<=new_cow) {
					for(int k=j;k<number_watchable_cows;k++) {
						cows[k]=cows[k+1];
					}
					number_watchable_cows--;
					j--;
				}
			}
			count += number_watchable_cows;
			cows[number_watchable_cows++]=new_cow;
		}
		printf("%d\n",count);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 

}
