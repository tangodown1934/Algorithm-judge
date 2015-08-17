#include <stdio.h>
int main()
{
	int i;
	int j;
	int k = 0;
	int num[10];
	int ans[10];
	int result[10];
	int count = 0;
	for (i = 0; i < 10; i++){
		scanf("%d", &num[i]);
		ans[i] = num[i] % 42;
	}
	for (i = 0; i < 10; i++){
		for (j = 0; j < 10; j++){
			if (result[j] == ans[i]){
				count++;
			}
		}
		if (count == 0){
			result[k] = ans[i];
			k++;
		}
		count = 0;
	}
	printf("%d\n", k);

	return 0;
}