#include <stdio.h>
int main()
{
	int n;
	int q;
	int startIndex;
	int endIndex;
	int i;
	int j;
	int arr[100002];
	int result[100002];
	int ans[100002];
	int sum = 0;
	scanf("%d", &n);
	for (i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
		sum = sum + arr[i];
		result[i] = sum;
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++){
		scanf("%d %d", &startIndex, &endIndex);
		ans[i] = result[endIndex]  - result[endIndex - startIndex];
	}
	for (i = 0; i < q; i++){
		printf("%d", ans[i]);
	}
	return 0;
}