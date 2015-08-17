#include <iostream>

using namespace std;

int main()
{
	int n;
	int* arr;
	int min;
	int* minIndices;
	int minNumber = 0;
	cin >> n;
	arr = new int[n];
	minIndices = new int[n];


	for (int i = 0; i < n; i++)
		cin >> arr[i];

	min = 1000;
	for (int i = 0; i < n; i++) 
	{
		if (arr[i] <= min) 
			min = arr[i];
	}

	for (int i = 0; i < n; i++)
	{
		if (min == arr[i]) {
			minIndices[minNumber++] = i;
		}
	}



	for (int i = 0; i < minNumber; i++)
		cout << minIndices[i]+1 << " ";
	cout << endl;

	delete arr;
	delete minIndices;

	return 0;
}