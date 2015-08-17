
#include <stdio.h>

//ATHLETIC
//ÆÈ¾¾¸§ ´ëÈ¸


char game[100] = { 0 };
int n;

int func(int index, int winN){
	if (index >= (n * 2 - 1) || winN == n){
		if (winN == n){
			for (int i = 0; i < index; i++)
			{
				printf("%c", game[i]);
			}
			printf("\n");
			return 1;
		}
		return 0;
	}
	int sum = 0;
	game[index] = 'o';
	sum += func(index + 1, winN + 1);
	game[index] = 'x';
	sum += func(index + 1, winN);
	return sum;
}

int main(){
	scanf("%d", &n);
	printf("total 10 case(s)\n",func(0, 0));
	return 0;
}