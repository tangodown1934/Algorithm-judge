#include <stdio.h>

#define START_YEAR 2013
#define START_G	   'G'
#define START_GAN  9

int main(){
	int N = 0;
	int startG,startGAN = 0;
	char GAN[10+1] = {0};
	char G[12+1]= {0};

	for(int i=0; i<10; i++){
		GAN[i] = i;
	}
	for(int k=0,i='A'; i<='L'; i++,k++){
		G[k] = i;
	}
	scanf("%d" , &N);
	for(int i=0;i<12;i++){
		if( G[i] == START_G ){
			startG = i;
		}
	}
	int resG,resGAN;
	resG = N - 2013;
	if( resG < 0 ) resG*=-1;
	resG += startG - 1;
	resG %= 12;
	resGAN = N - 2013;
	if( resGAN < 0 ) resGAN*=-1;
	resGAN += START_GAN;
	resGAN %= 10;

	printf("%c%d\n", G[resG],resGAN);
	return 0;
}