/*

VC, GCC���� ���

*/

#include <stdio.h>

int arr[10000];

void getChe(int num) {
	int i = 2;

	// �Է¹��� �� ��ŭ �迭�� ��� �ʱ�ȭ �صд�
	for (i = 2; i <= num; i++) {
		arr[i] = i;
	}

	for (i = 2; i <= num; i++) {
		if (arr[i] == 0) // �̹� üũ�� ���� ����� Ȯ������ �ʴ´�
			continue;
		for (int j = i + i; j <= num; j += i) { // i�� ������ i�� ������� 0���� üũ
			arr[j] = 0;
		}
	}

	// print
	for (i = 2; i <= num; i++) {
		if (arr[i] != 0)
			printf("%d\n", arr[i]);
	}
}

int main()
{
	getChe(100);
}