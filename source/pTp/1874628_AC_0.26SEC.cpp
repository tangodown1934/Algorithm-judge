#include <stdio.h>

void build(int input) {

	if(1==input) {
		printf("1");
		return ;
	}	

	build(input-1);
	printf("%d",input);
	build(input-1);

}





int main() {

	int input;
	scanf("%d",&input);

	build(input);
	printf("\n");
	
	return 0;
}
