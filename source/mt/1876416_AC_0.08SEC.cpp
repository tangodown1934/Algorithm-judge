
#include <stdio.h>

int N;

void func(int x){
	if (x == N) {
		printf("%d", x);
		return;
	}
	printf("%d", x);
	func(x + 1);
	printf("%d", x);
}

int main(){
	scanf("%d", &N);
	func(1);
	return 0;
}