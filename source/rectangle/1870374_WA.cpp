#include <stdio.h>


int main() {

	int width;
	scanf("%d",&width);

	int stack[100000]={0};
	int top=-1;
	long long int max=0;
	long long int min_height=2000000000;
	for(int i=0;i<width;i++) {
		int input;
		scanf("%d",&input);


		if(0==input) {
			top=-1;
			min_height=2000000000;
			continue;
		}

		stack[++top]=input;

		for(int j=0;j<=top;j++) {
			long long int tmp=stack[j];
			long long int cnt=0;
			for(int k=0;k<=top;k++) {
				if(stack[k]>=stack[j]) cnt++;
			}
			if(tmp*cnt>max) {
				max=tmp*cnt;
			}
		}

		if(min_height>=input) {
			min_height=input;
		}
		long long int tmp=min_height*(top+1);
		if(tmp>max) {
			max=tmp;
		}

	}
	printf("%lld\n",max);	


	return 0;

}
