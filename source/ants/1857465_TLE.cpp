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
	for(int i=0;i<n-1;i++){
		 flag = true;
		for(int j=0;j<n-1-i;j++){
			if(point[j]>point[j+1]){
				temp = point[j+1];
				point[j+1] = point[j];
				point[j]=temp;
				flag = false;
			}
		}
		if(flag==true) break;
	}
	int half,mintime=0,maxtime=0;
	half=l/2;

	for(int i=0;i<n;i++){
		if(half>point[i]){
			if(point[i]>mintime) mintime=point[i];
		}else{
			if((l-point[i])>mintime) mintime=(l-point[i]);
		}
	}

	maxtime = l - point[0];
	printf("%d %d",mintime,maxtime);
	return 0;
}
