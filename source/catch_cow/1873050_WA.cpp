#include <iostream>

using namespace std;

const int MAX_SIZE = 111111;
struct Queue {
	int front, rear;
	int arr[MAX_SIZE];

	Queue() {
		front = 0; rear = 0;
	}

	int pop()
	{
		if (empty())
			return -1;

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
	int nCount;

	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		cout << "#testcase" << itr + 1 << endl;

		int N, K;
		cin >> N >> K;

		int result = 0;
		Queue Q, time;
		bool chk[MAX_SIZE] = {};

		int t = 0;

		Q.push(N);
		time.push(t);

		int val = N;
		if (N > K) {
			result = N - K;
		}
		else
		{
			while (val != K)
			{
				val = Q.pop();
				result = time.pop();

				if (val == K) {
					break;
				}

				if (!chk[val - 1]) {
					Q.push(val - 1);
					time.push(result + 1);
					chk[val - 1] = true;
				}
				if (val > K) {
					if (2 * val < 2 * MAX_SIZE)
						if (!chk[2 * val]) {
							Q.push(2 * val);
							time.push(result + 1);
							chk[2 * val] = true;
						}

					if (!chk[val + 1]) {
						Q.push(val + 1);
						time.push(result + 1);
						chk[val + 1] = true;
					}
				}
				
			}
		}

		cout << result << endl;
	}

	return 0;
}