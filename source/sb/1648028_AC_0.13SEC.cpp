#include <stdio.h>

int main()
{
	int number[7], max = 0, max_index;

	for (int i = 0; i < 7; i++)
	{
		scanf("%d", &number[i]);
		if (max < number[i])
		{
			max = number[i];
			max_index = i;
		}
	}
	
	printf("%d\n", max_index + 1);

	return 0;
}