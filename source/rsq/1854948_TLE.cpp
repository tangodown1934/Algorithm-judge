#include <stdio.h>
#pragma warning(disable:4996)

//1.�Ҽ� �Ǻ�
 
  //�迭 ������=> 10000���� 11111, 30000���� 33333���� �����ϴ� ���� ����.

//2.�ִ�����

  //��Ŭ���� ȣ���� �̿�

//3.��Ģã��

  //���� ������


//�ּ� ��ġ ���
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

//������
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

//������
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
