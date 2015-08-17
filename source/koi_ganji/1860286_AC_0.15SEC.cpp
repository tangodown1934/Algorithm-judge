#include <stdio.h>

#define START_YEAR 2013
#define START_G	   'G'
#define START_GAN  9


int main(){
	int N = 0;
	int startG,startGAN = 0;
	char GAN[10+1] = {0};
	char G[12+1]= { 'A',
					'B',
					'C',
					'D',
					'E',
					'F',
					'G',
					'H',
					'I',
					'J',
					'K',
					'L' };
	
	scanf("%d" , &N);
	int val,resG,resGAN;
	val = N - 2013;
	if( val < 0 ){
		resGAN = (val+9) % 10;
		resG = (val+5) % 12 ;
	}else{
		resGAN = (val+9) % 10;
		resG = (val+ 5) % 12 ;
	}
	if( resGAN < 0 ) resGAN += 10;
	if( resG < 0 ) resG += 12;
	printf("%c%d\n", G[resG],resGAN);
	return 0;
}