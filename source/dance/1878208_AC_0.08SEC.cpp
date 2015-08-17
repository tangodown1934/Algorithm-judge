#include <stdio.h>
//DANCE
//20150719

int N;

int func(int left, int right){
	if (left == right) return 0;
	if (left + 1 == right){
		return left * right;
	}
	int mid = (right + left) / 2;
	return func(left, mid) + func(mid + 1, right);
}

int main(){

	scanf("%d", &N);

	printf("%d\n", func(1, N));

	return 0;
}