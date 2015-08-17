#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int n;
	int i;
	int x = 1;
	int y = 1;
	int flag = 0;
	scanf("%d", &n);
	for (i = 1; i < n; i++){	
		if (flag == 0){              //위
			y = y + 1;
			if (x == 1){
				//오른쪽으로가라
				flag = 1;
			}
			else if(x>y){
				//그대로 위로가라
				flag = 0;
			}
			else if (x == y){
				//왼쪽으로가라
				flag = 3;
			}
		}
		else if (flag == 1){         //오른쪽
			x = x + 1;
			if (x == y){
				//아래로가라
				flag = 2;
			}
			else if(y==1){
				//위로 가라
				flag = 0;
			}
		}
		else if (flag == 2){         //아래
			y = y - 1;
			if (y == 1){
				//오른쪽으로가라
				flag = 1;
			}
			else{
				//그대로 아래쪽으로 가라
				flag = 2;
			}
	
		}
		else if (flag == 3){         //왼쪽
			x = x - 1;
			if (x != 1){
				//그대로 왼쪽으로 가라
				flag = 3;
			}
			else{
				//위로 가라
				flag = 0;
			}
		}
		//printf("%d,%d\n", x, y);
	}
	printf("%d,%d\n", x, y);
	return 0;
}