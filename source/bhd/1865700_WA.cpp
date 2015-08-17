#include <stdio.h>

int N=0;
int score[80000 + 1] = { 0 };
int score_start[80000 + 1] = { 0 };
int hi[80000 + 1] = { 0 };


void func(){
	int max = 0;
	int cnt = 0;
	for (int i = 0; i < N; i++)
	{
		max = hi[i];
		for (int j = i+1; j < N; j++)
		{
			if (max <= hi[j])
				break;
			cnt++;
		}
	}
	printf("%d", cnt);
}

int main(){

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
	{
		scanf("%d", &hi[i]);
	}

	int pre = 0, pre_index = 0, pre_max = 0;
	int	count = 0, sum = 0;

	for (int i = 0; i < N; i++)
	{
		if (pre == 0 || hi[i] <= pre){

			score[count] = i - pre_index;
			sum += score[count];
			pre_index = i;
			pre_max = hi[i];
			count++;
		}
		else if (hi[i] > pre){

		}
		pre = hi[i];
	}

	printf("%d\n", sum);


	return 0;
}