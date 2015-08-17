#include <iostream>

using namespace std;

const int MAX_SIZE = 101;
class Queue {
	int front, rear;
	int arr[MAX_SIZE];

public:
	Queue() {
		front = 0; rear = 0;
	}

	int pop()
	{
		if (empty())
			return int(0);

		int val = arr[front++];
		front = front % MAX_SIZE;
		return val;
	}

	void push(int val)
	{
		if (front - rear == 1 || front - rear == -(MAX_SIZE - 1))
			return;

		arr[rear++] = val;
		rear = rear % MAX_SIZE;
	}

	bool empty()
	{
		return front == rear;
	}
};

int main()
{
	int N, M, arr[101][101];
	cin >> N;
	cin >> M;
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1;
	}

	Queue Q;
	bool chk[101] = { true, true };

	Q.push(1);
	while (!Q.empty())
	{
		int com = Q.pop();

		for (int i = 1; i <= N; i++)
		{
			if (arr[com][i] == 1 && !chk[i]) {
				chk[i] = true;
				Q.push(i);
			}
		}
	}

	int cnt = 0;

	for (int i = 2; i <= N; i++)
		if (chk[i])
			cnt++;

	cout << cnt << endl;

	return 0;
}