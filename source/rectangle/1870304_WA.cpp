#include <stdio.h>


int main() {

	int width;
	scanf("%d",&width);

	int stack[100000]={0};
	int top=-1;
	long long int max=0;
	int min_height=2000000000;
	int cnt1=0;
	for(int i=0;i<width;i++) {
		int input;
		scanf("%d",&input);


		if(1<input) {
			cnt1++;
		}
		if(1==input||0==input) {
			top=-1;
			min_height=2000000000;
			continue;
		}

		stack[++top]=input;

		for(int j=0;j<=top;j++) {
			int tmp=stack[j];
			int cnt=0;
			for(int k=j;tmp<=stack[k]&&k<=top;k++) {
				cnt++;
			}
			if(tmp*cnt>max) {
				max=tmp*cnt;
			}
		}

		if(min_height>=input) {
			min_height=input;
		}
		int tmp=min_height*(top+1);
		if(tmp>max) {
			max=tmp;
		}

	}
	printf("%lld\n",(max>cnt1)?max:cnt1);	


	return 0;

}
