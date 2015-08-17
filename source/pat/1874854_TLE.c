#include <stdio.h>

#define MAX 30

void Alg(int digit[MAX],int idx, int pos, int digitCount){
	
	int i,count=0;;
	if (idx == pos){
		for (i=0;i<pos; i++){
			if (digit[i] == 1){
				count ++;
			}
		}

		if (count == digitCount){
			for (i=0; i<pos; i++){
				printf("%d",digit[i]);
			}
			printf("\n");
			return;
		}

		else
			return ;
	}

	digit[idx] = 1;
	Alg(digit,idx+1,pos,digitCount);
	digit[idx] = 0;
	Alg(digit,idx+1,pos,digitCount);
}

int main()
{



	int digit[MAX] = {0};
	int i;
	int digitCount, pos;



		scanf("%d%d",&pos,&digitCount);


		Alg(digit,0,pos,digitCount);

		for (i=0; i<pos; i++){
			digit[i] = 0;
		}

	return 0;	
}