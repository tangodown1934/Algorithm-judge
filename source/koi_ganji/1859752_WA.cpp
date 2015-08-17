#include <iostream>

using namespace std;

char eeji[1111111];
int gan[1111111];

int main(void)
{
	char sipeeji = 'F';
	int sipgan = 9;

	for (int i = 2013; i <= 1000000; i++)
	{
		eeji[i] = sipeeji;
		gan[i] = sipgan;

		if (sipeeji == 'L')
			sipeeji = 'A';
		else
			sipeeji++;

		if (sipgan == 9)
			sipgan = 0;
		else
			sipgan++;
	}

	sipeeji = 'F';
	sipgan = 9;

	for (int i = 2013; i > 0; i--)
	{
		eeji[i] = sipeeji;
		gan[i] = sipgan;

		if (sipeeji == 'A')
			sipeeji = 'L';
		else
			sipeeji--;

		if (sipgan == 0)
			sipgan = 0;
		else
			sipgan--;
	}


	int val;
	cin >> val;

	cout << eeji[val] << gan[val] << endl;

	return 0;
}