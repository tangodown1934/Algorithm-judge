#include <iostream>

using namespace std;

int main()
{
	int N;
	int hi[80001];
	int top = -1;
	int data[80001];
	int index = 0;
	unsigned int cnt = 0;

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> hi[i];

	data[++top] = hi[index++];
	int val;
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

	cout << cnt << endl;

	return 0;
}
