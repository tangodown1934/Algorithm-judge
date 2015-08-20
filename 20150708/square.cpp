#include <stdio.h>

int gcd(int a, int b);

int main(){
	int m,n,i,j;
	int arr[100], min, sum=0;
	int flag=0;

	scanf("%d", &m);
	scanf("%d", &n);
	
	for(i=m;i<=n;i++){
		for(j=1;j<i;j++){
			if(j*j==i){
				if(flag++==0)
					min = i;
				sum += i;
				break;
			}
		}
	}
	printf("%d\n%d\n", sum,min);
}
