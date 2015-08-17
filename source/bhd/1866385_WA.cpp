#include <stdio.h>


int main()
{
	int N, hi[80001], top = -1, data[80001], index = 0, val;
	unsigned int cnt = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		scanf("%d", &hi[i]);

	data[++top] = hi[index++];
	while (index < N)
	{
		val = -1;
		if (top == -1)
			data[++top] = hi[index++];
		else
		{
			val = data[top--];
			if (val > hi[index])
			{
				data[++top] = val;
				cnt += (top + 1);
				data[++top] = hi[index++];
			}
		}
	}
	printf("%d\n", cnt);

	return 0;
}