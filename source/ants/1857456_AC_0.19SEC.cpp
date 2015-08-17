#include <stdio.h>
int main(){
	int len;
	int n;
	int arr[1000000];
	int fast = 0;
	int slow = 0;
	int temp;
	int temp2 = 0;
	int max = 0;
	int min = 0;
	scanf("%d %d", &len, &n);
	for (int i = 0; i < n; i++){
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < n; i++){
		if ((len - arr[i]) >= arr[i]){
			temp = arr[i];
			if (fast < temp){
				fast = temp;
			}
		}
		else{
			temp = (len - arr[i]);
			if (fast < temp){
				fast = temp;
			}
		}
	}

	for (int i = 0; i < n; i++){   //최대값
		if (max <= arr[i]){
			max = arr[i];
		}
	}

	min = arr[0];
	for (int i = 1; i < n; i++){   //최소값
		if (min >= arr[i]){
			min = arr[i];
		}
	}

	if (max <= (len - min)){
		slow = len - min;
	}
	else{
		slow = max;
	}

	printf("%d %d", fast, slow);

	return 0;
}