
#include <stdio.h>

int N;

void func(int x){
	if (x == 1){
		printf("%d", x);
		return;
	}
	while (x > 0){
		func(x - 1);
		printf("%d", x);
		x--;
	}

}

int main(){
	scanf("%d", &N);
	func(N);
	return 0;
}