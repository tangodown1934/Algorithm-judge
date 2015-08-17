#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct __data_t {
	int begin;
	long long int height;
} data_t;

int main() {

	int i, j, N, top = -1, n = -1;
	long long int max = 0;
	long long int* histogram;
	long long int* area;
	data_t* stack;

	scanf("%d", &N);
	histogram = (long long int*)malloc(sizeof(long long int)*N);
	area = (long long int*)malloc(sizeof(long long int)*N);
	stack = (data_t*)malloc(sizeof(data_t)*N);

	for(i = 0; i < N; i++)
		scanf("%lld", &histogram[i]);

	stack[++top].height = histogram[0];
	stack[top].begin = 0;
	for(i = 1; i < N; i++) {
		if(stack[top].height > histogram[i]) {
//			printf("area[%d] = stack[%d].height( %lld )*(%d - stack[%d].begin( %d ))\n", n + 1, top, stack[top].height, i, top, stack[top].begin);
			area[++n] = stack[top].height*(i - stack[top].begin);
			stack[top].height = histogram[i];
			j = top - 1;
			while(j > -1 && stack[j].height > histogram[i]) {
//				printf("area[%d] = stack[%d].height( %lld )*(%d - stack[%d].begin( %d ))\n", n + 1, j, stack[j].height, i, j, stack[j].begin);
				area[++n] = stack[j].height*(i - stack[j].begin);
				stack[j].height = histogram[i];
				j--;
			}
/*
			printf(">\n");
			for(j = 0; j <= top; j++)
				printf("(%lld %d)\t", stack[j].height, stack[j].begin);
			printf("\n");
			printf("Area : ");
			for(j = 0; j <= n; j++)
				printf("%lld ", area[j]);
			printf("\n");
*/
		}
		else if(stack[top].height < histogram[i]) {
			stack[++top].height = histogram[i];
			stack[top].begin = i;
/*
			printf("<\n");
			for(j = 0; j <= top; j++)
				printf("(%lld %d)\t", stack[j].height, stack[j].begin);
			printf("\n");
			printf("Area : ");
			for(j = 0; j <= n; j++)
				printf("%lld ", area[j]);
			printf("\n");
*/
		}
	}

	if(top > -1) {
		for(i = 0; i <= top; i++)
			area[++n] = stack[i].height*(N - stack[i].begin);
	}

//	for(i = 0; i <= n; i++)
//		printf("%lld ", area[i]);
//	printf("\n");

	for(i = 0; i <= n; i++)
		if(max < area[i]) max = area[i];
	printf("%lld\n", max);

	return 0;
}
