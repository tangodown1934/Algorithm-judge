#include <stdio.h>
//체스보드
//20150709


int main(){

	int N,i=0,cnt=1,rule=0,x,y,multi=1;
	int dis = 0;
	scanf("%d", &N);
	while(1){
		multi+=i;
		if( N <= multi ){
			break;
		}
		i+=2;
		cnt++;
	}
	dis = multi - N;
	x = y = cnt;
	rule = cnt%2;
	switch(rule){
	case 0:
		if( dis >= cnt ) {
			y--;
			x = (cnt - dis -1) * -1;
		}else{
			x = cnt - dis;
		}
		break;
	case 1:
		if( dis >= cnt ) {
			x--;
			y = (cnt - dis -1) * -1;
		}else{
			y = cnt - dis;
		}
		break;
	}
	printf("%d %d\n", x, y);
	return 0;
}