#include <stdio.h>

/* 
    �κ��� �̿��Ͽ� Ǯ��� ��. �� �׷��� �ð��ʰ�
    for�� 1������ Ǯ �� ����
    �Լ� P_SUM[N]={...} �Է¹��� ������ ���� ���� �迭�� ����
*/

int main(){
    int size = 100000;
    int n, q_size;
    int input, sum_arr[size], res_arr[size];
    int i, sum=0;
    int q_start, q_end;

    scanf("%d", &n);

    for(i=0;i<n;i++){
        scanf("%d", &input);
        if(i==0)
            sum_arr[i] = input;
        else
            sum_arr[i] = input+sum_arr[i-1];
    }
    
    scanf("%d", &q_size);
    
    for(i=0;i<q_size;i++){
        scanf("%d %d", &q_start, &q_end);
        if(q_start==1 && q_end==1)
            res_arr[i] = sum_arr[i];
        else
            res_arr[i] = sum_arr[q_end-1] - sum_arr[q_start-2]; 
    }
    for(i=0;i<q_size;i++){
        printf("%d\n",res_arr[i]);
    }
}