#include <stdio.h>

int count; 
int a;
int arr[100];

int upstair(int x)
{
	
	if (x > a){

		return 0;
		
	}
	if ( x ==a ){

		count++;
        return 0;
	}

	//printf("°æ·Î %d %d \n", x, a);


	upstair(x + 1);
	upstair(x + 2);

	return 0;

}

int main(void){


	int result;
	count = 0;

	scanf("%d", &a);

	upstair(0);

	printf("%d", count);


	return 0;
}