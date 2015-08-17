#include <iostream>
#include <cstring>

using namespace std;
const int MAX_SIZE = 11111111;
char alphabat[27] = { 0, 'A' };
char chk[27] = {};
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

			if (!chk[i]) {
				chk[i] = true;
				makePerm(index + 1, n + 1, alphabat[i]);
				index++;
				chk[i] = false;
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

			if (!chk[i]) {
				chk[i] = true;
				makeComb(index + 1, n + 1, alphabat[i]);
				index++;
				chk[i] = false;
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


		cin >> N >> R >> P >> Q;

		for (int i = 1; i <= N; i++) {
			chk[i] = true;
			makePerm(1, 1, alphabat[i]);
			chk[i] = false;
		}

		for (int i = 1; i <= N; i++) {
			chk[i] = true;
			makeComb(1, 1, alphabat[i]);
			chk[i] = false;
		}

		showPerm(P);
		showComb(Q);

	return 0;
}