#include <iostream>

using namespace std;

int main()
{
	int n;
	int* arr;
	int q;
	int total = 0;

	cin >> n;

 	arr = new int[n + 1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		total += arr[i];
	}

	cin >> q;

	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		int sum = 0;

		if (b - a < 50000) {
			for (int j = a; j <= b; j++)
				sum += arr[j];
		}
		else {
			int invSum = 0;
			for (int j = 1; j < a; j++)
				invSum += arr[j];
			for (int j = b + 1; j <= 100000; j++)
				invSum += arr[j];

			sum = total - invSum;
		}

		cout << sum << endl;
	}

	delete arr;

	return 0;
}