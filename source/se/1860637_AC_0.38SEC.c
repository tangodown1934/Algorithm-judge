#include <stdio.h>
#include <string.h>

#define STR_LEN 10000

int main(void){

	int inNum;
	int i;
	int length=0;

	char numStr[STR_LEN];
	scanf("%d",&inNum);

	for (i=1; length<inNum; i++) {
		sprintf(numStr,"%d",i);
		length+=strlen(numStr);
	}

	printf("%c \n",numStr[strlen(numStr)-length+inNum-1]);
	
	return 0;
}