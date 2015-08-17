#include <iostream>

using namespace std;

char eeji[11111];
int gan[11111];

int main(void)
{
	char sipeeji = 'A';
	int sipgan = 0;

	for (int i = 1; i <= 10000; i++)
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


	int val;
	cin >> val;

	cout << eeji[val] << gan[val] << endl;

	return 0;
}