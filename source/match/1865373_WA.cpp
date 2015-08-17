#include <iostream>

using namespace std;

class Stack{
public:
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
			return _data[_top--];
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

int indices[51][2];
int index = 0;
int mpair = true;

int main()
{
	char str[51] = "(b-c)+((((((a+b)+c)+d)+e)+f)+g)+(e*g)+h+)";
	Stack stk(51);

	cin >> str;

	for (int i = 0; str[i] != '\0'; i++)
		if (str[i] == '(')
		{
			mpair = false;
			stk.push(str[i]);
		}
		else if (str[i] == ')')
		{
			if (stk.isEmpty())
				mpair = false;
			else
				mpair = true;
			stk.pop();
		}

	if (mpair)
	{
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '(')
			{
				indices[index++][0] = i;
				stk.push(str[i]);
			}
			else if (str[i] == ')')
			{
				indices[--index][1] = i;
				cout << indices[index][0] << " " 
					<< indices[index][1] << endl;
			}
		}
	}
	else
	{
		cout << "not match" << endl;
	}

	return 0;
}