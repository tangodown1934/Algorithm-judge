#include <stdio.h>




int func(int x, int y){
	if (y == 0) return 1;
	return func(x, y - 1) * x;
}


int main(){

	int x, y;
	scanf("%d %d", &x, &y);
	printf("%d\n",func(x, y));

	return 0;
}