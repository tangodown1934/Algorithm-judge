/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <string.h>

int main()
{

	int itr, i;
	int nCount;		/* 문제의 테스트 케이스 */
	char ch[1000];

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */
	scanf("\n");

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);
		
		gets(ch);

		for(i=0;i<strlen(ch);i++){
			if(ch[i]!=' '){
				printf("%c",ch[i]);
			}
		}
		printf("\n");
	}
	
	return 0;	/* 반드시 return 0으로 해주셔야합니다. */ 
}