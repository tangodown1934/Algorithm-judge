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
			return;
		}

		_data[++_top] = val;
	}

	int pop()
	{
		if (isEmpty())
		{
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

int result[51][2];
int index = 0;
int number = 0;

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
			result[index++][0] = i;
			//start = i;
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
// 			if (end == -1)
// 				end = i;
			result[--index][1] = i;
			number++;
			stk.pop();
		}
	}

	if (stk.getSize() == 0)
	{
		for (int i = number-1; i >= 0; --i)
		{
			cout << result[i][0] << " " << result[i][1] << endl;
		}
		//cout << start << " " << end << endl;
	}
	else
	{
		cout << "not match" << endl;
	}

	return 0;
}