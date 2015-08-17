#include <stdio.h>


typedef struct _stack{
	int left[100000];
	int data[100000];
	int right[100000];
	int top;
}Stack;

int main() {

	int width;
	scanf("%d",&width);

	Stack stack;
	stack.top=-1;
	long long int max=0;
	long long int min_height=2000000000;
	for(int i=0;i<width;i++) {
		int input;
		scanf("%d",&input);

		stack.data[++stack.top]=input;
		stack.left[stack.top]=i;
		stack.right[stack.top]=i;
		
		for(int j=stack.top-1;j>=0;j--) {
			if(stack.data[j]>input) break;
			stack.right[j]=i;
		}

		for(int j=stack.top-1;j>=0;j--) {
			if(stack.data[j]<input) break;
			stack.left[stack.top]=j;
		}

	}

	for(int i=0;i<=stack.top;i++) {
		long long int tmp = stack.data[i]*(stack.right[i]-stack.left[i]+1);
		if (max<tmp) {
			max=tmp;
		}
	}

	printf("%lld\n",max);	


	return 0;

}
