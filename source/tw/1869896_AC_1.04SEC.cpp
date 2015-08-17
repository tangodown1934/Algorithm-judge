#include <iostream>

using namespace std;

struct To {
	int h;
	int i;
};

int main()
{
	To arr[500001];
	To stk[500001];
	int num[500001] = {};
	int top = 0;
	int N;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> arr[N - i].h;
		arr[N - i].i = N - i;
	}

	int index = 1;
	stk[top++] = arr[index++];
	while (index <= N)
	{
		To val = stk[--top];

		if (arr[index].h > val.h) {
			num[val.i] = N + 1 - index;
		}
		else {
			stk[top++] = val;
			stk[top++] = arr[index++];
		}

		if (top == 0)
			stk[top++] = arr[index++];
	}

	for (int i = 0; i < N; i++) {
		cout << num[N - i] << " ";
	}
	cout << endl;

	return 0;
}