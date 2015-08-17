#include <iostream>

using namespace std;

int N = 10;
int hi[80001];
int top = -1;
int data[80001];

int index = 0;
unsigned int cnt = 0;

int main()
{
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> hi[i];
	}

	data[++top] = hi[index++];
	while (index < N)
	{
		int val = data[top--];
		if (val == -1)
		{
			data[++top] = hi[index++];
		}
		if (val > hi[index])
		{
			data[++top] = val;
			cnt += (top+1);
			data[++top] = hi[index++];
		}

	}

	cout << cnt << endl;

	return 0;
}
