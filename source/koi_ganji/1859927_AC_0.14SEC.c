#include <stdio.h>

#define MAX_LEN 60

int tenFunc(int num){
	int ten[10] = {9,0,1,2,3,4,5,6,7,8};

	return ten[num%10];
}

char tweFunc(int num){
	char tweleve[12] = {'L','A','B','C','D','E','F','G','H','I','J','K'};

	return tweleve[num%12];
}

void Alg(int num){
	printf("%c%d\n",tweFunc(num+9),tenFunc(num+7));
}
int main(void){

	int num,result,i;
	int tenTemp[MAX_LEN];
	char tweTemp[MAX_LEN];

	scanf("%d",&num);
	Alg(num);

	return 0;
}