#include <iostream>

using namespace std;

int N = 10;
int	hi[80001];// = { 1, 4, 4, 6, 3, 6, 9, 1, 7, 7 };
//int hi[80000];
int index = 0;
int cnt;

int test(int prev, int adder)
{
	int pres = hi[index + 1];
	if (index >= N || pres == 0)
	{
		return cnt;
	}

	if (adder == 0)
	{
		index += 1;
		adder = 1;
		prev = pres;
		pres = hi[index + 1];
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
	int nCount = 0;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		cout << "#testcase" << itr + 1 << endl;

		int result;

		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> hi[i];
		}

		result = test(hi[0], 1);

		cout << result << endl;
	}
	

	return 0;
}