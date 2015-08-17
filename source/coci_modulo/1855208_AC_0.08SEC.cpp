#include <stdio.h>
//³ª¸ÓÁö
//20150708


int main(){
	int val[42]={0};
	int a[10+1] = {0};
	int i,cnt=0;

	for(i=0;i<10;i++){
		scanf("%d",&a[i]);
		val[a[i]%42] = 1;
	}
	
	for(i=0; i<42; i++){
		if( val[i] == 1 )
			cnt++;
	}
	printf("%d\n",cnt);
	return 0;
}