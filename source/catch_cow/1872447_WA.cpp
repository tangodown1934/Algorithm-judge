#include <iostream>

using namespace std;

const int MAX_SIZE = 100001;
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

	int N, K;
	cin >> N >> K;

	int result = 0;
	Queue Q, time;

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
			cout << val << endl;
			result = time.pop();

			if (val == K) {
				break;
			}

			Q.push(2 * val);
			time.push(result + 1);
			Q.push(val - 1);
			time.push(result + 1);
			Q.push(val + 1);
			time.push(result + 1);

		}
	}

	cout << result << endl;


	return 0;
}