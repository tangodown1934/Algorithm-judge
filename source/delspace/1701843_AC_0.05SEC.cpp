#include <stdio.h>

int main()
{
	char str[1000];
	int position= 0;
	gets(str);

	for (int i = 0; i < 1000; i++)
	{
		if (str[i] != ' ')
		{
			str[position++] = str[i];
		}
	}

	puts(str);

	return 0;
}