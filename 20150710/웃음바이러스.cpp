#include <stdio.h>

/*

7 7
0 1 1 1 0 1 1
1 1 1 1 1 1 0
1 1 0 1 1 1 1
1 1 1 0 1 1 0
1 0 0 0 1 1 0
1 1 1 1 1 1 1
0 1 0 1 1 0 1
2 2

*/

int main(){
	int nCount;
	int i, j, k, l;
	int x, y, move_x, move_y, count, max;
	int arr[100][100], al_arr[100][100];
	bool flag;

	scanf("%d", &nCount);

	for (i = 0; i < nCount; i++){
		printf("Test case %d\n", i + 1);

		count = 0;
		flag = false;
		scanf("%d %d", &x, &y);
		for (j = 0; j < x; j++){
			for (k = 0; k < y; k++){
				scanf("%d", &arr[j][k]);
				al_arr[j][k] = 0;
				if (arr[j][k] == 1)
					count++;
			}
		}

		scanf("%d %d", &move_x, &move_y);
		move_x--;
		move_y--;

		l = 1;
		al_arr[move_x][move_y] = 1;
		printf("\n%d\n", count);
		while (l<count){
			for (j = 0; j < x; j++){
				for (k = 0; k < y; k++){
					if (arr[j][k] !=0){
						printf("\n");
						if (l >= count) // 모두 세면 끝
							break;

						if (j == move_x && k == move_y){ // 첫 폭탄 맞은 것부터 처리
							flag = true; 
						}
						
						if (flag == false) // 첫 폭탄을 맞은 이후부터 실행
							continue;

						if (al_arr[j][k] == 1){ // 이미 한번 돈 경우만 해당


							if (j - 1 >= 0){
								if (arr[j - 1][k] == 1 && al_arr[j - 1][k] == 0){
									arr[j - 1][k] = arr[j][k] + 1;
									al_arr[j - 1][k] = 1;
									l++;
									printf("%d : %d : top\n", j, k);
								}
							}
							if (k - 1 >= 0){
								if (arr[j][k - 1] == 1 && al_arr[j][k - 1] == 0){
									arr[j][k - 1] = arr[j][k] + 1;
									al_arr[j][k - 1] = 1;
									l++;
									printf("%d : %d : left\n", j, k);
								}
							}
							if (arr[j + 1][k] == 1 && al_arr[j + 1][k] == 0){
								arr[j + 1][k] = arr[j][k] + 1;
								al_arr[j + 1][k] = 1;
								l++;
								printf("%d : %d : bottom\n", j, k);
							}
							if (arr[j][k + 1] == 1 && al_arr[j][k + 1] == 0){
								arr[j][k + 1] = arr[j][k] + 1;
								al_arr[j][k + 1] = 1;
								l++;
								printf("%d : %d : right\n", j, k);
							}
						}
					}
				}
			}
		}
		
		// Print 
		for (j = 0; j < x; j++){
			for (k = 0; k < y; k++){
				printf("%d ", arr[j][k]);
			}
			printf("\n");
		}
		max = arr[0][0];
		// Print 
		for (j = 0; j < x; j++){
			for (k = 0; k < y; k++){
				if (max < arr[j][k])
					max = arr[j][k];
			}
		}
		printf("\nmax = %d", max);
	}
}