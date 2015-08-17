#include <stdio.h>

int decimal = 0,hexadecimal = 0,duodecimal = 0;

int deci(int num, int x, int dec){
	if (num < dec) return num;
	return deci(num / dec, x, dec) + num % dec * x;
}

int main(){
	for (int i = 2991; i < 10000; i++)
	{
		decimal = deci(i, 1, 10);
		duodecimal = deci(i, 1, 12);
		hexadecimal = deci(i, 1, 16);
		//printf("%d %d %d\n", decimal, duodecimal, hexadecimal);
		if (duodecimal == decimal  && hexadecimal == decimal ){
			printf("%d\n", i);
		}
		
	}

	return 0;
}