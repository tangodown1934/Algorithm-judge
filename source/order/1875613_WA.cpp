/*

	������ ���� (���)

*/

#include <stdio.h>

void get_pc(int idx, int n, int r, char* str, int* p_pcnt, int* p_qcnt, int p, int q, char* parr, char* qarr) {	
	int i;
	char cpystr[15];
	int samecnt;

	if(idx == r) {
		//����
		(*p_pcnt)++;
		if(*p_pcnt == p) {
			// printf("-------p match :");
			//���� ��� ����
			for(i=0; i<r; i++) {
				// printf("%c", str[i]);
				parr[i] = str[i];
			}

			//���� ��� �̹� ������ ���
			if(*p_qcnt >= q) {
				for(i=0; i<r; i++) {
					printf("%c", parr[i]);				
				}
				printf("\n");
				for(i=0; i<r; i++) {
					printf("%c", qarr[i]);				
				}
				printf("\n");
			}
		}

		// ����
		// ���ڰ� �ڷΰ����� Ŀ��
		bool is_combination = true;
		for(i=1; i<r; i++) {
			if(str[i] <= str[i-1]) {
				is_combination = false;
				break;
			}
		}
		
		if(is_combination) {
			for(i=0; i<r; i++) {
				qarr[i] = str[i];
			}
			(*p_qcnt)++;

			// ����� ����
			if((*p_qcnt) == q) {	
				// printf("-------q match :");
				//�̹� ���� ����� ������ ���
				if(*p_pcnt >= p) {
					for(i=0; i<r; i++) {
						printf("%c", parr[i]);				
					}
					printf("\n");
					for(i=0; i<r; i++) {
						printf("%c", qarr[i]);				
					}
					printf("\n");
				}
			}
		} 
		return;
	}

	bool is_already;
	for(i=0; i<n; i++) {
		is_already = false;
		// ���� �ߺ��˻�
		/*
			0~24�� �迭�� �� ���ڸ� 1�� �ٲ㵵 ��
			visit ó�� 
		*/
		for(int j=0; j<idx; j++) {
			if(str[j] == 65+i) {
				is_already = true;
				break;
			}
		}

		if(!is_already) {
			if(*p_pcnt <= p || *p_qcnt <= q) {
				str[idx] = 65+i;
				// recursive
				get_pc(idx+1, n, r, str, p_pcnt, p_qcnt, p, q, parr, qarr);  
			}
		}
	}
	
}

int main()
{

	int itr;
	int nCount;		/* ������ �׽�Ʈ ���̽� */
	int n, r;
	int p, q;  //p���� q����
	int p_pcnt, p_qcnt;
	char str[15];
	char qarr[15] = {};
	char parr[15] = {};

	scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	for(itr=0; itr<nCount; itr++)
	{
		p_pcnt = 0;
		p_qcnt = 0;

		printf("#testcase%d\n",itr+1);

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);
		get_pc(0, n, r, str, &p_pcnt, &p_qcnt, p, q, parr, qarr);

	}

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}