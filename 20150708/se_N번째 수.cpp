#include <stdio.h>

int getSize(int num) // ��ȣ�� ���̸� ����
{
	int size = 0;
	while (num>0)
	{
		num /= 10;
		size++;
	}
	return size;
}

int getNumAt(int num, int index)
// ��ȣ�� index��° ���� ����
{
	if (index == 0) return num % 10;
	// 0�� ������ �ڸ��� ����ó��

	for (int i = 0; i < index; i++)
	{
		num /= 10;
	}
	return num % 10;
}

int main()
{
	int N, sum = 0, i = 0;

	scanf("%d", &N);

	while (sum < N)
		sum += getSize(++i);

	// if (sum != n) sum -= getSize(i);

	printf("%d\n", getNumAt(i, (sum-N)));
}