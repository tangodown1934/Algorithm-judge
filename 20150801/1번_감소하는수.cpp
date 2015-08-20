#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 11111
#define LL long long

LL q[SIZE];
int rear;

void qsort(LL arr[], int left, int right)
{
	int l = left;
	int r = right;
	LL temp;
	LL pivot = arr[(left + right) / 2];

	do{
		while (pivot > arr[l]) l++;
		while (pivot < arr[r]) r--;

		if (l <= r)
		{
			temp = arr[l];
			arr[l] = arr[r];
			arr[r] = temp;
			l++; r--;
		}
	} while (l < r);
	if (left < r) qsort(arr, left, r);
	if (right > l) qsort(arr, l, right);
}

void recursion(LL current)
{
	LL a = current % 10;
	
	q[rear++] = current;
	for (LL i = a - 1; i >= 0; --i)
	{
		recursion(current * 10 + i);
	}
}
int main(){
	rear = 0;
	q[rear++] = 0;
	for (int i = 1; i < 10; ++i)
		recursion(i);

	qsort(q, 0, rear-1);

	int N;
	scanf("%d", &N);
	
	if (rear <= N) printf("-1\n");
	else printf("%lld\n", q[N]);

	return 0;
}