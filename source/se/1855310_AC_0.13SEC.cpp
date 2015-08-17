	#include <iostream>

	using namespace std;

	int main()
	{
		int input;
		int count = 0;
		int val2;

		cin >> input;

		for (int i = 1; count < input; i++)
		{
			int adder = 1;
			int factor = 10;

			while (i % factor != i)
			{
				factor *= 10;
				adder++;
			}

			count += adder;
			val2 = i;
		}

		int diff = count - input;
		int factor = 10;
		int count2 = 1;
		int *arr = new int[8];
		while (val2 != 0)
		{
			int temp = (val2 % factor);
			int temp2 = (int)(factor / 10.0);
			arr[count2-1] = temp / temp2;

			val2 -= temp;
			factor *= 10;
			count2++;
			
		}
		cout << arr[diff] << endl;

		delete arr;

		return 0;
	}