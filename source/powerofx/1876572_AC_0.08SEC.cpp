#include <stdio.h>

int pow(int x, int y)
{
   
		if(y == 1){
			return x;
		}

	return x*pow(x, y - 1);


}

int main(void){

	int a, b;
	int result;
	scanf("%d %d", &a, &b);
	
	result = pow(a, b);
	printf("%d", result);


	return 0;
}