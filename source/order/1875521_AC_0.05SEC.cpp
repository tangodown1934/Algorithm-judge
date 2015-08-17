#include <iostream>
#include <cstring>

using namespace std;
char alphabat[27] = { 0, 'A' };
char chk[27] = {};
char perm[13] = {};
char comb[13] = {};
char permResult[13] = {};
char combResult[13] = {};
int N, R, P, Q;
int cnt1 = 1;
int cnt2 = 1;

bool permResultFlag = false;
bool combResultFlag = false;

void showPerm(int index)
{
	for (int i = 1; i <= R; i++)
		cout << permResult[i];
	cout << endl;
}

void showComb(int index)
{
	for (int i = 1; i <= R; i++)
		cout << combResult[i];
	cout << endl;
}

void makePerm(int n, char ch)
{
	if (n == R) {
		perm[n] = ch;
		cnt1++;
		if (cnt1 - 1 == P) {
			memcpy(permResult, perm, sizeof(char) * 13);
			permResultFlag = true;
		}
	}
	else {
		perm[n] = ch;

		for (int i = 1; i <= N; i++) {
			if (!chk[i]) {
				chk[i] = true;
				makePerm(n + 1, alphabat[i]);
				chk[i] = false;
			}

			if (permResultFlag)
				return;
		}
	}
}

void makeComb(int n, int ch)
{
	if (n == R) {
		comb[n] = ch;
		cnt2++;
		if (cnt2 - 1 == Q) {
			memcpy(combResult, comb, sizeof(char) * 13);
			combResultFlag = true;
		}
	}
	else {
		comb[n] = ch;

		for (int i = ch + 1 - 'A'; i <= N; i++) {
			if (!chk[i]) {
				chk[i] = true;
				makeComb(n + 1, alphabat[i]);
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
		makePerm(1, alphabat[i]);
		chk[i] = false;
	}

	for (int i = 1; i <= N; i++) {
		chk[i] = true;
		makeComb(1, alphabat[i]);
		chk[i] = false;
	}

	showPerm(P);
	showComb(Q);

	return 0;
}