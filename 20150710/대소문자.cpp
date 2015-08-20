/*

VC, GCC에서 사용

*/

#include <stdio.h>

size_t my_strlen(char *ch){
	int i = 0;
	size_t count = 0;
	while (ch[i++] != '\0'){
		count++;
	}
	return count;
}

int main()
{

	int itr, j=0;
	int nCount;		/* 문제의 테스트 케이스 */
	char ch[11111] = { 0, };

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{

		printf("#testcase%d\n", itr + 1);

		scanf("%s", ch);
		
		j = 0;
		for (j = 0; j < my_strlen(ch);j++){
			if(ch[j] >= 97 && ch[j] <= 122)
				ch[j] -= 32;
			else
				ch[j] += 32;
		}
		printf("%s\n", ch);
	}


	return 0;	/* 반드시 return 0으로 해주셔야합니다. */
}