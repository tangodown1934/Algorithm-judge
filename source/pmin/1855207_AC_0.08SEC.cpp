#include <stdio.h>
#include <string.h>
//최소값 출력
//20150708

int main(){
	int n=0,a[100+1]={0},b[100+1]={0},i=0,min=9876543,cnt=0;
	
	scanf("%d", &n);
	
	for(i=0; i<n; i++){
		scanf("%d", &a[i]);
	}

	for(i=0;i<n;i++){
		if( a[i] < min ){
			memset(b,0,sizeof(b));
			cnt=0;
			min = a[i];
			b[cnt++]=i+1;
		}else if( a[i] == min ){
			b[cnt++]=i+1;
		}
	}
	for(i=0; i<cnt; i++){
		printf("%d ", b[i]);
	}
	printf("\n");
	return 0;
}