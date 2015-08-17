#include <stdio.h>

int S, _S;
int x, y, dx, dy;
int n=2, case_flag;

int _x, _y;
int multi;

int main()
{
	scanf("%d %d %d %d %d", &S, &x, &y, &dx, &dy);

	while(1)
	{
		_S = S;
		_x = x + multi*dx;
		_y = y + multi*dy;

		while (1)
		{	
			if (_x > _S && _y > _S)
			{
				_S = S*n;
				n++;
			}
			else
			{
				break;
			}
		}
		
		if ((_x > _S && _y < _S) || (_x<_S && _y > _S))
		{
			if (_x % S == 0 || _y % S == 0)
				case_flag = 1;
			else
				case_flag = 0;
			break;
		}

		multi++;
	}
	
	switch (case_flag)
	{
	case 0:
		printf("After %d jumps the flea lands at (%d, %d).\n", multi, _x, _y);
		break;
	case 1:
		printf("The flea cannot escape from black squares.\n");
		break;
	}


	return 0;
}