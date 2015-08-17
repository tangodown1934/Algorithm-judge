
#include <stdio.h>

int bin[100] = { 0 };
int n, k;
void func(int index, int oneN){
	if (index == n){
		if (oneN == k){
			for (int i = 0; i < n; i++)
			{
				printf("%d", bin[i]);
			}
			printf("\n");
		}
		return;
	}
	if (oneN < k){
		bin[index] = 1;
		func(index + 1, oneN + 1);
	}
	bin[index] = 0;
	func(index + 1, oneN);
}

int main(){
	scanf("%d %d", &n, &k);
	func(0, 0);
	return 0;
}