#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

int main()
{
	int n;
	int i;
	int x = 1;
	int y = 1;
	int flag = 0;
	scanf("%d", &n);
	for (i = 1; i < n; i++){	
		if (flag == 0){              //��
			y = y + 1;
			if (x == 1){
				//���������ΰ���
				flag = 1;
			}
			else if(x>y){
				//�״�� ���ΰ���
				flag = 0;
			}
			else if (x == y){
				//�������ΰ���
				flag = 3;
			}
		}
		else if (flag == 1){         //������
			x = x + 1;
			if (x == y){
				//�Ʒ��ΰ���
				flag = 2;
			}
			else if(y==1){
				//���� ����
				flag = 0;
			}
		}
		else if (flag == 2){         //�Ʒ�
			y = y - 1;
			if (y == 1){
				//���������ΰ���
				flag = 1;
			}
			else{
				//�״�� �Ʒ������� ����
				flag = 2;
			}
	
		}
		else if (flag == 3){         //����
			x = x - 1;
			if (x != 1){
				//�״�� �������� ����
				flag = 3;
			}
			else{
				//���� ����
				flag = 0;
			}
		}
		//printf("%d,%d\n", x, y);
	}
	printf("%d,%d\n", x, y);
	return 0;
}