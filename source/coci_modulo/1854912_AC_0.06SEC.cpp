#include <iostream>

using namespace std;

const int n = 10;
const int val = 42;

int main()
{
	int arr[n];
	int remains[val] = {};
	int count = 0;

	for (int i = 0; i < n; i++)
		cin >> arr[i];

	for (int i = 0; i < n; i++)
	{
		int temp = arr[i] % val;
		remains[temp] = 1;
	}

	for (int i = 0; i < val; i++)
	{
		if (remains[i] != 0)
			count++;
	}

	cout << count << endl;

	return 0;
}