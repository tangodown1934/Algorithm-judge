#include <stdio.h>

int N;
int case_flag;
int plus, x, y;


int main()
{
	scanf("%d", &N);
	
	while (1)
	{
		for (int i = 0; i < 1; i++)
		{
			x++;
			N--;
			if (N==0) break;
		}
		if (N == 0) break;
		for (int i = 0; i < plus; i++)
		{
			y++;
			N--;
			if (N == 0) break;
		}
		if (N == 0) break;
		for (int i = 0; i < plus; i++)
		{
			x--;
			N--;
			if (N == 0) break;
		}
		if (N == 0) break;
		plus++;
		for (int i = 0; i < 1; i++)
		{
			y++;
			N--;
			if (N == 0) break;
		}
		if (N == 0) break;
		for (int i = 0; i < plus; i++)
		{
			x++;
			N--;
			if (N == 0) break;
		}
		if (N == 0) break;
		for (int i = 0; i < plus; i++)
		{
			y--;
			N--;
			if (N == 0) break;
		}
		if (N == 0) break;
		plus++;
	}
	
	printf("%d %d\n", x, y+1);

	return 0;
}