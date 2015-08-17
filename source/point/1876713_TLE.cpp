
#include <stdio.h>
//POINT

int x1, x2, y1, y2, maxX, maxY;
int mulX, mulY;

int func(int x, int y){
	if (y == 0) return x;
	return func(y, x % y);
}

int cnt(int x, int y){
	if (x == maxX && y == maxY){
		return 1;
	}
	return cnt(x + mulX, y + mulY) + 1;
}

int main(){
	scanf("%d %d", &x1, &y1);
	scanf("%d %d", &x2, &y2);
	int sum_x=0, sum_y=0;

	if (!((x1 < 0 && x2 < 0) || (x1 > 0 && x2 > 0))){
		if (x1 < 0) sum_x += -x1;
		else        sum_x += x1;
		if (x2 < 0) sum_x += -x2;
		else        sum_x += x2;
	}
	else{
		sum_x = x2 - x1;
		if (sum_x < 0) sum_x *= -1;
	}
	if (!((y1 < 0 && y2 < 0) || (y1 > 0 && y2 > 0))){
		if (y1 < 0) sum_y += -y1;
		else        sum_y += y1;
		if (y2 < 0) sum_y += -y2;
		else        sum_y += y2;
	}
	else{
		sum_y = y2 - y1;
		if (sum_y < 0) sum_y *= -1;
	}

	
	int multi = 0;
	multi = func(sum_x, sum_y);

	mulX = sum_x / multi;
	mulY = sum_y / multi;

	if (x1 > x2){
		maxX = x1; maxY = y1;
		printf("%d\n",cnt(x2, y2));
	}
	else if (x1 == x2){
		if (y1 > y2){
			maxX = x1; maxY = y1;
			printf("%d\n", cnt(x2, y2));
		}
		else{
			maxX = x2; maxY = y2;
			printf("%d\n", cnt(x1, y1));
		}
	}
	else{
		maxX = x2; maxY = y2;
		printf("%d\n",cnt(x1, y1));
	}


	return 0;
}