#include <stdio.h>

double SQRT(double, double);

int main()
{
	double input, x, result;
	while (1)
	{
		scanf_s("%lf", &input);
		scanf_s("%lf", &x);
		result = SQRT(input, x);
		printf("��������? : %lf \n", result);
	}

	return 0;
}

double SQRT(double input, double x)
{
	for (int i = 0; i<10; i++) { x = (x + (input / x)) / 2; }    // �� ���� ���� �ָ����� �Ӹ��� �㳲 �Ф�
	return x;
}