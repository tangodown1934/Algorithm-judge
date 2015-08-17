#include <stdio.h>
int gcd(int x, int y)
{

	if (y == 0){

		return x;
	}

	return gcd(y,(x%y));


}

int main(void){

	int a, b;
	int result,lcd;
	scanf("%d %d", &a, &b);

	if (a == b){
		
		
		result = a;
		lcd = a;

	}
	else{
		result = gcd(a, b);
		lcd = (a*b) / result;
	}
	printf("%d %d", result, lcd);


	return 0;
}

