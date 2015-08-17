#include <iostream>
#include <cstring>

using namespace std;
const int MAX_SIZE = 11111111;
char alphabat[27] = { 0, 'A' };
char perm[MAX_SIZE][13] = {};
char comb[MAX_SIZE][13] = {};
char permResult[MAX_SIZE][13] = {};
char combResult[MAX_SIZE][13] = {};
int N, R, P, Q;
int cnt1 = 1;
int cnt2 = 1;

bool permResultFlag = false;
bool combResultFlag = false;

void showPerm(int index)
{
	for (int i = 1; i <= R; i++)
		cout << permResult[index][i];
	cout << endl;
}

void showComb(int index)
{
	for (int i = 1; i <= R; i++)
		cout << combResult[index][i];
	cout << endl;
}

void makePerm(int index, int n, char ch)
{
	if (n == R) {
		perm[index][n] = ch;
		memcpy(permResult[cnt1++], perm[index], sizeof(char) * 13);
		if (cnt1 - 1 == P)
			permResultFlag = true;
	}
	else {
		perm[index][n] = ch;

		for (int i = 1; i <= N; i++) {
			memcpy(perm[index + 1], perm[index], sizeof(char) * (n + 1));

			int flag = true;
			for (int j = 1; j <= n; j++)
			{
				if (alphabat[i] == perm[index + 1][j]) {
					flag = false;
					break;
				}
			}

			if (flag)
			{
				makePerm(index + 1, n + 1, alphabat[i]);
				index++;
			}

			if (permResultFlag)
				return;
		}
	}
}

void makeComb(int index, int n, int ch)
{
	if (n == R) {
		comb[index][n] = ch;
		memcpy(combResult[cnt2++], comb[index], sizeof(char) * 13);
		if (cnt2 - 1 == Q)
			combResultFlag = true;
	}
	else {
		comb[index][n] = ch;

		for (int i = ch + 1 - 'A'; i <= N; i++) {
			memcpy(comb[index + 1], comb[index], sizeof(char) * 13);

			int flag = true;
			for (int j = 1; j <= n; j++)
			{
				if (alphabat[i] == comb[index + 1][j]) {
					flag = false;
					break;
				}
			}

			if (flag)
			{
				makeComb(index + 1, n + 1, alphabat[i]);
				index++;
			}

			if (combResultFlag)
				return;
		}
	}
}

int main()
{
	for (int i = 2; i < 26; i++)
		alphabat[i] = alphabat[1] + i - 1;

	{
		for (int i = 0; i < MAX_SIZE; i++)
		{
			memset(perm[i], 0, sizeof(char) * 13);
			memset(comb[i], 0, sizeof(char) * 13);
			memset(permResult[i], 0, sizeof(char) * 13);
			memset(combResult[i], 0, sizeof(char) * 13);
		}
		cnt1 = cnt2 = 1;

		cin >> N >> R >> P >> Q;

		for (int i = 1; i <= N; i++)
			makePerm(1, 1, alphabat[i]);

		for (int i = 1; i <= N; i++)
			makeComb(1, 1, alphabat[i]);

		showPerm(P);
		showComb(Q);
	}

	return 0;
}