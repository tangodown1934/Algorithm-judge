#include <iostream>

using namespace std;

int main()
{
	int n;
	int* arr;
	int q;

	int data[101][101] = {};

	cin >> n;

	arr = new int[n + 1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	cin >> q;

	int a, b;
	for (int i = 0; i < q; i++) {
		cin >> a >> b;

		int sum = 0;

		if (data[a][b] == 0) {
			for (int j = a; j <= b; j++)
				sum += arr[j];
		}
		else {
			sum = data[a][b];
		}
		
		cout << sum << endl;
	}

	delete arr;

	return 0;
}