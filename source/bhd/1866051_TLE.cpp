#include <iostream>

using namespace std;

class Stack {
public:
	int data[80001];
	int top;

	Stack()
	{
		top = -1;
	}

	void push(int val)
	{
		data[++top] = val;
	}

	int pop()
	{
		if (isEmpty())
		{
			return -1;
		}

		return data[top--];
	}

	bool isEmpty()
	{
		return top == -1;
	}

	int getSize()
	{
		return top + 1;
	}
};

int N = 10;
long int hi[100000];

Stack stk;
int index = 0;
int cnt = 0;

int main()
{
	
	{
		
		cin >> N;
		for (int i = 0; i < N; i++)
		{
			cin >> hi[i];
		}

		stk.push(hi[index++]);
		while (index < N)
		{
			int val = stk.pop();
			if (val == -1)
			{
				stk.push(hi[index++]);
			}
			if (val > hi[index])
			{
				stk.push(val);
				cnt += stk.getSize();
				stk.push(hi[index++]);
			}

		}

		cout << cnt << endl;
	}
	

	return 0;
}
