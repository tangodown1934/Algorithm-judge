/*

VC, GCC���� ���

*/

#include <stdio.h>

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	int count;
	char ch[1000];
	int i,j,temp;
	
	
	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for(itr=0; itr<nCount; itr++)
	{

		printf("#testcase%d\n",itr+1);

		scanf("%d %s", &count, ch);
		for(i=0;i<count;i++){
			for(j=i+1;j<count;j++){
				if(ch[i]==ch[j]){
					if((j-i-1)%2==0)
						ch[i]=ch[j]='x';
				}
			}
		}
		
		for(i=0;i<count;i++){
			if(ch[i]!='x')
				printf("%c",ch[i]);
		}
		printf("\n");
	}
	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}