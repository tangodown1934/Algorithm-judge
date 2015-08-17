#include<stdio.h>

int main(){
	int l,n;
	int point[100000]={0};
	scanf("%d %d",&l,&n);
	for(int i=0;i<n;i++){
		scanf("%d",&point[i]);
	}
	//sorting
	int temp=0;
	bool flag =true;
	
	int half,mintime=0,maxtime=0;
	half=l/2;

	for(int i=0;i<n;i++){
		if(half>point[i]){
			if(point[i]>mintime) mintime=point[i];
		}else{
			if((l-point[i])>mintime) mintime=(l-point[i]);
		}
	}
	int min = point[0];
	int max = point[0];
	for (int i = 1; i < n; i++){   //ÃÖ¼Ò°ª
        if (min >= point[i]){
            min = point[i];
        }

		if (max <= point[i]){
            max = point[i];
        }
    }

	if(l - min>max){
		maxtime = l - min;
	}else{
		maxtime =max;
	}
	printf("%d %d",mintime,maxtime);
	return 0;
}
