#include <stdio.h>

int getSize(int num) // 번호의 길이를 구함
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
// 번호의 index번째 수를 구함
{
	if (index == 0) return num % 10;
	// 0은 마지막 자리로 예외처리

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