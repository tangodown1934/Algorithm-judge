#include <iostream>

using namespace std;

class Stack{
private:
	int _max_size;
	int* _data;
	int _top;

public:

	Stack(int size)
	{
		_max_size = size;
		_data = new int[size];
		_top = -1;
	}

	~Stack()
	{
		if (_data)
			delete _data;
	}

	int getSizeLimit()
	{
		return _max_size;
	}

	int getSize()
	{
		return _top + 1;
	}

	bool isEmpty()
	{
		return _top == -1;
	}

	void push(int val)
	{
		if (_top + 1 == _max_size)
		{
			cout << "stack is full" << endl;
			return;
		}

		_data[++_top] = val;
	}

	int pop()
	{
		if (isEmpty())
		{
			cout << "stack is empty" << endl;
			return 0;
		}
		else
		{
			return _data[--_top];
		}
	}

	int top()
	{
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			return _data[_top];
		}
	}

	int bottom()
	{
		if (isEmpty())
		{
			return 0;
		}
		else
		{
			return _data[0];
		}
	}
};

int main()
{
	char str[51] = "(a*(b+c)+d)";
	Stack stk(51);
	int start, end = -1;

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (str[i] == '(')
		{
			start = i;
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (end == -1)
				end = i;
			stk.pop();
		}
	}

	if (stk.getSize() == 0)
	{
		cout << start << " " << end << endl;
	}
	else
	{
		cout << "not match" << endl;
	}

	return 0;
}