#include <stdio.h>
int main()
{
	int n;
	int q;
	int startIndex;
	int endIndex;
	int i;
	int j;
	int arr[100001];
	int result[100001];
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}
	scanf("%d", &q);
	for (i = 0; i < q; i++){
		scanf("%d %d", &startIndex, &endIndex);
		result[i] = 0;
		for (j = startIndex - 1; j < endIndex; j++){
			result[i] = result[i] + arr[j];
		}
	}

	//������
	for (i = 0; i < q; i++){
		printf("%d\n", result[i]);
	}
	
	return 0;
}