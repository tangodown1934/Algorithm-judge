#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int myceil(float num) {
	if(num==(int)num) {
		return (int)num;
	} else {
		return (int)(num+1);
	}
}

int compare (const void *first,const void *second)
{
    if (*(int*)first > *(int*)second)
        return 1;
    else if (*(int*)first < *(int*)second)
        return -1;
    else
        return 0;
}


int main() {
	
	int L;
	int num;
	int *arr;

	scanf("%d %d",&L,&num);

	arr = (int *)malloc(num*sizeof(int));
	for(int i=0;i<num;i++) {
		scanf("%d",&arr[i]);
	}

	int min=0;
	for(int i=0;i<num;i++) {
		if(min<((arr[i]>L-arr[i])?L-arr[i]:arr[i])) {
			min=(arr[i]>L-arr[i])?L-arr[i]:arr[i];
		}
	}	

	qsort(arr,num,sizeof(int),compare);

	int mid = num/2;
	int time1=myceil((arr[mid]-arr[mid-1])/2);
	arr[mid]-=time1;
	int time2=myceil((arr[mid+1]-arr[mid])/2);
	arr[mid]+=time2;
	int max = time1+time2+((arr[mid]>L-arr[mid])?arr[mid]:L-arr[mid]);

	printf("%d %d",min,max);

	return 0;
}
