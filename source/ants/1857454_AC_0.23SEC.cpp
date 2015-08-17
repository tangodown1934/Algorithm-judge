#include <stdio.h>
//개미떼
//20150709

int main(){
	int ants_num=0,L=0,ants_pos[1000000  +1]={0};
	int i;
	int mid=0,fast=0,slow=0,min=98765432,max=-1;
	scanf("%d %d", &L,&ants_num);
	mid = L/2;//중앙을 포함해서 모두 위쪽으로
	for(i=0;i<ants_num; i++){
		scanf("%d", &ants_pos[i]);
		//fast
		if( ants_pos[i] >= mid ){
			if( fast < (L - ants_pos[i]) ){
				fast = L - ants_pos[i];
			}
		}
		else{
			if( fast < ants_pos[i] ){
				fast = ants_pos[i];
			}
		}

		//slow
		if( ants_pos[i] < mid ){
			if( min > ants_pos[i] ){
				min = ants_pos[i];
			}
		}else{
			if( max < ants_pos[i] ){
				max = ants_pos[i];
			}
		}


		slow = L - min;
		if( max > slow ){
			slow = max;
		}
	}
	
	printf("%d %d\n", fast,slow);


	return 0;
}