#include <stdio.h>

#define MAX_LEN 60

int tenFunc(int num){
	int ten[10] = {9,0,1,2,3,4,5,6,7,8};

	return ten[num%10];
}

char tweFunc(int num){
	char tweleve[12] = {'K','A','B','C','D','E','F','G','H','I','J'};

	return tweleve[num%12];
}

int main(void){

	int num,result,i;
	int tenTemp[MAX_LEN];
	char tweTemp[MAX_LEN];

	tenTemp[0] = tenFunc(0);
	tweTemp[0] = tweFunc(0);

	for (i=1; i<MAX_LEN; i++){
		tenTemp[i] = tenFunc(i);
		tweTemp[i] = tweFunc(i);
	}


	scanf("%d",&num);
	printf("%c%d\n",tweFunc(num%60),tenFunc(num%60));


	return 0;
}