#include <stdio.h>
#include <string.h>
int main()
{
	char arr[55];
	int temp[55];
	int ans[55];
	int index = -1;
	int j = 0;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++){
		if (arr[i] == '('){
			index++;
			temp[index] = i;
		}
		else if (arr[i] == ')'){
			printf("%d %d\n", temp[index], i);
			index--;
		}
	}

	return 0;
}