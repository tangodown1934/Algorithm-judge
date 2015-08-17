#include <stdio.h>

int main()
{
	int number[7], result=0;
	
	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &number[i]);
		result += number[i];
	}
		
	printf("%d\n", result);
	return 0;
}