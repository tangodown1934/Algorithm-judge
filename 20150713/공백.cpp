/*

VC, GCC���� ���

*/

#include <stdio.h>
#include <string.h>

int main()
{

	int itr, i;
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	char ch[1000];

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */
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
	
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 
}