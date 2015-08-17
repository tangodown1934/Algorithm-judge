#include <iostream>
#include <cmath>

using namespace std;

const int MAX_SIZE = 111111;

template <typename T>
class Queue {
public:
	T Q[MAX_SIZE];
	int front, rear;

	Queue()
	{
		front = 0;
		rear = 0;
	}

	bool empty()
	{
		return front == rear;
	}

	void push(T val)
	{
		Q[rear++] = val;
		rear %= MAX_SIZE;
	}

	T pop()
	{
		if (!empty())
		{
			T val = Q[front++];
			front %= MAX_SIZE;
			return val;
		}
		return T();
	}
};

struct To {
	int val, level;
	To(){}
	To(int val, int level) :val(val), level(level){}
};

bool isPrime[MAX_SIZE];

void allPrime()
{
	for (int i = 1; i < MAX_SIZE; i++)
		isPrime[i] = true;

	for (int i = 2; i < MAX_SIZE; i++)
		for (int j = 2; i*j < MAX_SIZE; j++)
			isPrime[i*j] = false;
}

int getJari(int val, int n)
{
	int adder = 1;
	int jari = val % (adder * 10);
	for (int j = 0; j < n; j++) {
		val -= jari * adder;
		adder *= 10;
		jari = val % (adder * 10) / adder;
	}

	return jari;
}

int main()
{
	allPrime();

	int nCount;
	cin >> nCount;
	for (int itr = 0; itr < nCount; itr++)
	{
		cout << "#testcase" << itr + 1 << endl;

		int start, end;
		cin >> start >> end;

		int result = 0;
		bool chk[MAX_SIZE] = {};
		Queue<To> Q;

		Q.push(To(start, 0));
		while (!Q.empty())
		{
			To pick = Q.pop();

			if (pick.val == end) {
				result = pick.level;
				break;
			}

			for (int i = 0; i < 4; i++)
			{
				int tmp = pick.val;
				int compJari = getJari(pick.val, i);

				int adder = 1;
				for (int j = 0; j < i; j++)
					adder *= 10;

				if (compJari == 9)
					tmp -= 9 * adder;
				else
					tmp = (tmp + adder);

				int jari = getJari(tmp, i);
				while (jari != compJari)
				{
					if (!chk[tmp] && isPrime[tmp])
					{
						Q.push(To(tmp, pick.level + 1));
						chk[tmp] = true;
					}

					if (jari == 9)
						tmp -= 9 * adder;
					else
						tmp += adder;

					jari = getJari(tmp, i);
				}

				jari * adder;
			}
		} // while end

		cout << result << endl;
	}

	return 0;
}