#include<stdio.h>

int main(){
	int num[10];
	int module[10];

	printf("입력\n");
	for(int i=0;i<10;i++){
		scanf("%d",&num[i]);
	}

	for(int i=0;i<10;i++){
		module[i] = num[i]%42;
	}

	int count=10;
	for(int i=0;i<9;i++){
		if(module[i]==module[i+1]) count--;
	}

	printf("출력\n%d",count);

	return 0;
}