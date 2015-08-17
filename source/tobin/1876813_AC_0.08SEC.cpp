#include <stdio.h>

void binary(int x)
{

	if (x== 0){
		return;
	}

	
	binary(x/2);
	printf("%d", x % 2);
	return;

}

int main(void){

	int a;;
	scanf("%d", &a);
	binary(a);
	
	


	return 0;
}