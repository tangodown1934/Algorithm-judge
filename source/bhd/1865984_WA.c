#define _CRT_SECURE_NO_WARNINGS

/*

VC, GCC에서 사용

*/

#include <stdio.h>
#include <stdlib.h>

typedef struct __bound_t {
	int begin, end;
} bound_t;

int main()
{

	int itr;
	int nCount;		/* 문제의 테스트 케이스 */

	scanf("%d", &nCount);	/* 테스트 케이스 입력 */

	for (itr = 0; itr<nCount; itr++)
	{
		int i, n_Cow;
		int* height;
		bound_t stack[1024];
		int top = -1;
		int max, sub_begin, sub_end;
		int cnt = 0;

		printf("#testcase%d\n", itr + 1);

		scanf("%d", &n_Cow);
		height = (int*)malloc(sizeof(int)*n_Cow);

		for (i = 0; i < n_Cow; i++)
			scanf("%d", &height[i]);

		stack[++top].begin = 0;
		stack[top].end = n_Cow - 1;

		while (top > -1) {
			sub_begin = stack[top].begin;
			sub_end = stack[top--].end;
//			printf("Begin : %d\t End : %d\n", sub_begin, sub_end);
			max = sub_end;
			for (i = sub_begin; i <= sub_end; i++)
				if (height[max] < height[i]) max = i;

//			printf("Pivot Value height[%d] : %d\n", max, height[max]);
//			printf("newly added number : %d\n", sub_end - max);
			cnt += sub_end - max;

			// left-side
			if (sub_begin <= max - 1) {
				stack[++top].begin = sub_begin;
				stack[top].end = max - 1;
			}

			// right-side
			if (max + 1 <= sub_end) {
				stack[++top].begin = max + 1;
				stack[top].end = sub_end;
			}

		}

		printf("%d\n", cnt);
		free(height);
	}

	return 0;	/* 반드시 return 0으로 해주셔야합니다. */

}