#include<stdio.h>
#include<math.h>
int main(){

	int T;
	scanf("%d",&T);

	double index_r =(sqrt((double)T));
	int index = (int)index_r;
	
	int x=0,y=0;
	int k;
	k=index*index;
	if(k!=T){
		index++;
		k=index*index;
	}
	if(k%2==1){
		int diff = k-T;
		if(index>diff){
			x= diff+1;
			y= index;
		}else{
			x= index;
			y= index-(diff-index+1);
		}
	}else{
		int diff = k-T; 
		if(index>diff){
			x= index;
			y= diff+1;
		}else{
			x= index-(diff-index+1);
			y= index;
		}
	}

	printf("%d %d",x,y);
	return 0;
}