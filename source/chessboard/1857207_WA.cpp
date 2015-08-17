#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int** arr;
	int N;
	int t = 0;

	int sector;

	cin >> N;

	int n = (int)sqrt(N);
	if (n*n < N)
		n+=2;

	arr = new int*[n+1];
	for (int i = 0; i < n+1; i++)
		arr[i] = new int[n+1];

	int currentX = 1;
	int currentY = 1;
	int number = 1;
	int resultX, resultY;

	arr[currentX][currentY] = number;
	for (t = 1; t < n; t+=2)
	{
		arr[++currentX][currentY] = ++number;

		for (int i = 0; i < t; i++)
			arr[currentX][++currentY] = ++number;

		for (int i = 0; i < t; i++)
			arr[--currentX][currentY] = ++number;

		arr[currentX][++currentY] = ++number;

		for (int i = 0; i < t + 1; i++)
			arr[++currentX][currentY] = ++number;

		for (int i = 0; i < t + 1; i++)
			arr[currentX][--currentY] = ++number;
	}

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			if (arr[i][j] == N) {
				resultX = j;
				resultY = i;
			}
		}
	}
	cout << resultX << " " << resultY << endl;

	return 0;
}