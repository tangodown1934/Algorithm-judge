#include <iostream>

using namespace std;

int main()
{
	int n;
	int* arr;
	int q;
	int** sec;

	cin >> n;
	//n = 7;

	arr = new int[n+1];
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
// 	arr[1] = 6;
// 	arr[2] = 2;
// 	arr[3] = 9;
// 	arr[4] = 8;
// 	arr[5] = 3;
// 	arr[6] = 4;
// 	arr[7] = 7;

	cin >> q;
	//q = 3;

	sec = new int*[q];
	for (int i = 0; i < q; i++)
		sec[i] = new int[2];

// 	sec[0][0] = 1; sec[0][1] = 1;
// 	sec[1][0] = 1; sec[1][1] = 2;
// 	sec[2][0] = 3; sec[2][1] = 7;
	for (int i = 0; i < q; i++) {
		cin >> sec[i][0] >> sec[i][1];

		int sum = 0;

		for (int j = sec[i][0]; j <= sec[i][1]; j++)
			sum += arr[j];

		cout << sum << endl;
	}

	return 0;
}