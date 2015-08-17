#include <iostream>

using namespace std;

int main()
{
	int N, hi[80001], top = -1, data[80001], index = 0, val;
	unsigned int cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hi[i];

	data[++top] = hi[index++];
	while (index < N)
	{
		val = data[top--];
		if (top == -1)
			data[++top] = hi[index++];
		else
		{
			if (val > hi[index])
			{
				data[++top] = val;
				cnt += (top + 1);
				data[++top] = hi[index++];
			}
		}
	}

	cout << cnt << endl;

	return 0;
}
