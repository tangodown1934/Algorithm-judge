#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 10000
#define QSIZE 11111

int prime[SIZE];
int q[QSIZE];
int qCnt[QSIZE];
int modnum[5];
int check[SIZE];

void toArr(int n, int arr[])
{
	int temp;

	temp = n;
	for (int i = 3; i >= 0; i--)
	{
		arr[i] = temp % 10;
		temp /= 10;
	}
}

void createPrime()
{
	int i, j;

	for (i = 1000; i < SIZE; i++)
		prime[i] = 0;

	for (i = 2; i*i < SIZE; i++)
	{
		for (j = i * 2; j < SIZE; j += i)
		{
			prime[j] = 1;
		}
	}
}

int main()
{
	int n, nCount;
	int A, B;
	int i, j;

	scanf("%d", &nCount);
	for (n = 0; n < nCount; n++)
	{
		createPrime(); // 소수를 만들어둔다

		int front;
		int rear;
		int num, temp;
		int count;
		int next, x, y;

		scanf("%d %d", &A, &B);

		for (i = 0; i < SIZE; i++)
		{
			check[i] = 0;
		}

		count = front = rear = 0;

		//push
		q[rear] = A;
		qCnt[rear] = count;
		rear++;
		check[A] = 1; // 중복
		while (front != rear)
		{
			// pop
			num = q[front];
			count = qCnt[front];
			front++;

			if (num == B)
				break;

			toArr(num, modnum);
			for (i = 0; i < 4; i++)
			{
				x = 1;
				next = 0;
				for (j = 0; j < 4; j++)
				{
					if (i != j)
						next += modnum[3 - j] * x;
					x *= 10;
				}

				y = 1;
				for (j = 0; j < i; j++)
				{
					y *= 10;
				}

				for (j = 0; j < 10; j++)
				{
					if (prime[next] == 0 && check[next] == 0 && next>1000)
					{
						q[rear] = next;
						qCnt[rear] = count + 1;
						rear++;

						check[next] = 1;
					}
					next += y;
				}
			}
		}
		printf("%d\n", count);
	}
	return 0;
}
