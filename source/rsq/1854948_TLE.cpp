#include <stdio.h>
#pragma warning(disable:4996)

//1.소수 판별
 
  //배열 사이즈=> 10000개면 11111, 30000개면 33333으로 설정하는 것이 좋다.

//2.최대공약수

  //유클리드 호제법 이용

//3.규칙찾기

  //완전 제곱수


//최소 위치 출력
//int main()
//{
//	int n;
//	int i;
//	int arr[111];
//	int min;
//	scanf("%d", &n);
//	for (i = 0; i < n; i++){
//		scanf("%d", &arr[i]);
//	}
//	for (i = 1; i < n; i++){
//		min = arr[0];
//		if (min>=arr[i]){
//			min = arr[i];
//		}
//	}
//	for (i = 0; i < n; i++){
//		if (min == arr[i]){
//			printf("%d ", i+1);
//		}
//	}
//}

//나머지
//int main()
//{
//	int i;
//	int j;
//	int k = 0;
//	int num[10];
//	int ans[10];
//	int result[10];
//	int count = 0;
//	for (i = 0; i < 10; i++){
//		scanf("%d", &num[i]);
//		ans[i] = num[i] % 42;
//	}
//	for (i = 0; i < 10; i++){
//		for (j = 0; j < 10; j++){
//			if (result[j] == ans[i]){
//				count++;
//			}
//		}
//		if (count == 0){
//			result[k] = ans[i];
//			k++;
//		}
//		count = 0;
//	}
//	printf("%d\n", k);
//
//	return 0;
//}

//구간합
int main()
{
	int n;
	int q;
	int startIndex;
	int endIndex;
	int i;
	int j;
	int arr[100000];
	int result[100000];
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

	for (i = 0; i < q; i++){
		printf("%d\n", result[i]);
	}
	

	return 0;
}
