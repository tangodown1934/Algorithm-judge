#pragma warning(disable:4996)
#include <stdio.h>

int main()
{
	int x, y;
	int w, h;
	int time;
	int i;
	int count_x, count_y;

	scanf("%d %d", &w, &h);
	scanf("%d %d", &x, &y);
	scanf("%d", &time);

	count_x = count_y = 1;
	for (i = 0; i < time%(2*w); i++){
		if (x >= w)
			count_x = -1;
		if (x <= 0)
			count_x = 1;
		x += count_x;
	}
	for (i = 0; i < time % (2 * h); i++){
		if (y >= h)
			count_y = -1;
		if (y <= 0)
			count_y = 1;
		y += count_y;
	}
	printf("%d %d\n", x, y);

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}