#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>

#define SIZE 11111
#define STRSIZE 22

int N;
char dict[SIZE][STRSIZE];
int cnt[SIZE];

// Quick sorting for String 2-Array 
void qsort(char arr[][STRSIZE], int left, int right)
{
	int l = left;
	int r = right;
	char temp[STRSIZE];
	char pivot[STRSIZE];
	strcpy(pivot, arr[(left + right) / 2]);

	do{
		while (strcmp(pivot, arr[l])>0) l++;
		while (strcmp(pivot, arr[r])<0) r--;

		if (l <= r){
			strcpy(temp, arr[l]);
			strcpy(arr[l], arr[r]);
			strcpy(arr[r], temp);
			l++; r--;
		}
	} while (l<r);
	if (left < r) qsort(arr, left, r);
	if (right > l) qsort(arr, l, right);
}

int count(char str[]){
	int cnt = 0; while (str[++cnt] != '\0'){};
	return cnt;
}

int main()
{
	int n, nCount;

	scanf("%d", &nCount);
	for (n = 0; n < nCount; n++)
	{
		int i, j;
		int flag, cmp; // expression for bool
		int m,c;

		flag = 1; // Initialize

		// Input
		scanf("%d", &N);
		for (i = 0; i < N; i++){
			scanf("%s", &dict[i]);
		}

		qsort(dict, 0, N - 1); // Quick sorting

		for (i = 0; i < N; i++)
			cnt[i] = count(dict[i]); // Get such length of string

		for (i = 0; i < N-1; i++){
			cmp = 1;
			for (j = 0; j < cnt[i]; j++)
				if (dict[i][j] != dict[i + 1][j])
					cmp = 0;

			if (cmp){
				flag = 0;
				break;
			}
		}
		// Result
		if (flag) printf("YES");
		else printf("NO");
		printf("\n");
	}

	return 0;
}