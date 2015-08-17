#include <stdio.h>

int N=0;
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
	func();
	return 0;
}