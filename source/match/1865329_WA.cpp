#include <stdio.h>
#include <string.h>
int main()
{
	char arr[55];
	int temp[55];
	int temp2[55];
	int index = -1;
	int index2 = -1;
	int count = 0;
	int flag = 0;
	scanf("%s", arr);
	for (int i = 0; i < strlen(arr); i++){
		if (arr[i] == '('){
			index++;
			temp[index] = i;
		}
		else if (arr[i] == ')'){
			if (index == -1){
				printf("not match\n");
				flag = 1;
				break;
			}
			index2++;
			temp2[index2] = temp[index--];
			index2++;
			temp2[index2] = i;
		}
	}

	if (flag == 1){
		printf("not match\n");
	}
	else{
		for (int i = 0; i <= index2; i++){
			printf("%d ", temp2[i]);
			count++;
			if (count % 2 == 0){
				printf("\n");
			}
		}
	}

	return 0;
}