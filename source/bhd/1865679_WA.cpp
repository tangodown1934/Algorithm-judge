#include <iostream>

using namespace std;

int N = 6;
int	hi[80000] = { 5, 2, 4, 2, 6, 1 };
int index = 0;
int cnt;

int test(int prev, int adder)
{
	if (index >= N)
	{
		return cnt;
	}

	int pres = hi[index + 1];
	if (adder == 0)
	{
		index += 2;
		adder = 1;
		prev = pres;
		pres = hi[index];
	}

	if (pres < prev)
	{
		cnt += adder;
		index++;
		test(pres, adder + 1);
	}
	else
	{
		int pprev = hi[index - 1];

		test(pprev, adder - 1);
	}
}

int main()
{
	int result;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> hi[i];
	}

	result = test(hi[0], 1);

	cout << result << endl;

	return 0;
}