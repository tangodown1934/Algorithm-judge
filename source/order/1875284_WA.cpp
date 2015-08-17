/*

VC, GCC���� ���

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int compare(const void *a , const void *b) {
    return strcmp( (char*)a , (char*)b );
}

void get_pc(int idx, int n, int r, char* str, int* p_pcnt, int* p_qcnt, int p, int q, char (*qarr)[111]) {	
	int i;
	char cpystr[15];
	int samecnt;

	if(idx == r) {
		//����
		(*p_pcnt)++;
		if(*p_pcnt == p) {
			// printf("-------p match :");
			for(i=0; i<r; i++) {
				printf("%c", str[i]);				
			}
			printf("\n");
		}

		strcpy(cpystr, str);
		qsort(cpystr, r, sizeof(cpystr[0]) , compare);

		// ����
		// ���� �� �ߺ��˻�
		bool is_same;
		for(i=0; i<(*p_qcnt); i++) {
			samecnt = 0;
			is_same = false;
			for(int j=0; j<r; j++) {
				if(qarr[i][j] == cpystr[j]) {
					samecnt++;
				}
			}
			if(samecnt == r) {
				is_same = true;
				break;
			}
		}

		// �̹� ���� ������
		if(!is_same) {
			for(i=0; i<r; i++) {
				qarr[(*p_qcnt)][i] = str[i];
			}
			(*p_qcnt)++;

			if((*p_qcnt) == q) {	
				// printf("-------q match :");
				for(i=0; i<r; i++) {
					printf("%c", str[i]);				
				}
				printf("\n");
			}
		} 
		return;
	}

	bool is_already;
	for(i=0; i<n; i++) {
		is_already = false;
		// ���� �ߺ��˻�
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
				get_pc(idx+1, n, r, str, p_pcnt, p_qcnt, p, q, qarr);  
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
	char qarr[111][111];

	// scanf("%d", &nCount);	/* �׽�Ʈ ���̽� �Է� */

	// for(itr=0; itr<nCount; itr++)
	// {
		p_pcnt = 0;
		p_qcnt = 0;
		for(int i=0; i<111; i++) {
			for(int j=0; j<111; j++) {
				qarr[i][j] = -1;
			}
		}
		// printf("#testcase%d\n",itr+1);

		scanf("%d %d", &n, &r);
		scanf("%d %d", &p, &q);
		get_pc(0, n, r, str, &p_pcnt, &p_qcnt, p, q, qarr);

	// }

	return 0;	/* �ݵ�� return 0���� ���ּž��մϴ�. */ 

}