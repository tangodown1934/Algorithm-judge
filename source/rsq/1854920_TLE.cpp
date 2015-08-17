#include <iostream>

using namespace std;

int main()
{
	int n;
	int* arr;
	int q;
	int** sec;

	cin >> n;

	arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;

	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		int sum = 0;

		for (int j = a; j <= b; j++)
			sum += arr[j];

		cout << sum << endl;
	}

	return 0;
}