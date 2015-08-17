#include <stdio.h>

void hanoi(int n, int x, int y, int z)
{

	if (n>0){
		hanoi(n - 1, x, z, y);
		printf("%d -> %d\n", x, z);
		hanoi(n - 1, y, x, z);
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	hanoi(n, 1, 2, 3);
}
 