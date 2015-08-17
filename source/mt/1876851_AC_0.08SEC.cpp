#include <stdio.h>
int a;

void mt(int x)
{
	if (x > a)
	{
		return;

	}
	if (x == a){
		
		printf("%d",a);
		return;

	}

	
	printf("%d", x);
	mt(x+1);
	printf("%d", x);
	return;

}

int main(void){

	
	scanf("%d", &a);
	mt(1);
	return 0;
}
