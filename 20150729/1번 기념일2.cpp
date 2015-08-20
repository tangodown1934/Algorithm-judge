#pragma warning(disable:4996)
#include <stdio.h>

#define SIZE 111111

int arr[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 }; // month 

int main()
{
	char str[SIZE];
	int ac;
	int year, month, day;

	int i, j;

	scanf("%s", str);
	scanf("%d", &ac);

	ac--;
	
	year = 0;
	year = year + (str[0] - '0') * 1000;
	year = year + (str[1] - '0') * 100;
	year = year + (str[2] - '0') * 10;
	year = year + (str[3] - '0') * 1;

	month = 0;
	month = month + (str[5] - '0') * 10;
	month = month + (str[6] - '0') * 1;

	day = 0;
	day = day + (str[8] - '0') * 10;
	day = day + (str[9] - '0') * 1;

	day += ac; // ���� ���

	// ���� ��� 
	arr[2] = 28;
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // ���� ��� 4�� ����̸鼭 100�� ����� �ƴҶ� �Ǵ� 400�� ����϶�
	{
		arr[2] = 29;
	}

	while (day > arr[month])
	{
		day = day - arr[month];
		if (month == 12) // �ذ� �ٲ�� ��
		{
			year += 1;
			month = 1;

			// ���� ���
			if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) // ���� ���
			{
				arr[2] = 29;
			}
			else{
				arr[2] = 28;
			}
		}else{
			month++;
		}
	}
	
	printf("%d-", year);
	
	if (month<10)
	{
		printf("0%d-", month);
	}
	else{
		printf("%d-", month);
	}

	if (day < 10){
		printf("0%d", day);
	}else{
		printf("%d", day);
	}
	printf("\n");

	return 0;
}