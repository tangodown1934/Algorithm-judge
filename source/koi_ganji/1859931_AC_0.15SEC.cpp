#include<stdio.h>

char ch[12]={'A','B','C','D','E','F','G','H','I','J','K','L'};//0-2-4
int one[10]={0,1,2,3,4,5,6,7,8,9};
int prime[1000000][2];

int main(){
	int year;
	scanf("%d",&year);//1 ¡Â N ¡Â 1 000 000 
	
	int s_year=2013-2004;
	int cnt=0;

	int x= year%12+8;
	int y= year%10+6;
	if(x>=12){
		x-=12;
	}
	if(y>10){
		y-=10;
	}
	printf("%c%d",ch[x],one[y]);
	return 0;
}