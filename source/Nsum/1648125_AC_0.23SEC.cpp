#include <stdio.h>

int main()
{
	int number, result=0;
	int i = 1;
	scanf("%d", &number);
	while (1)
	{
		result += i++;
		if (result == number) break;		
	}
		
	printf("%d\n", i-1);
	return 0;
}