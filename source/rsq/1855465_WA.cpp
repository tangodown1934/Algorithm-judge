#include <stdio.h>

/* 
    �κ��� �̿��Ͽ� Ǯ��� ��. �� �׷��� �ð��ʰ�
    for�� 1������ Ǯ �� ����
    �Լ� P_SUM[N]={...} �Է¹��� ������ ���� ���� �迭�� ����
*/

int p_sum(int i){
    return i;
}

int main(){ 
    int size, q_size;
    int arr[111111], sum_arr[11111];
    int i, sum=0;
    int q_start, q_end;

    scanf("%d", &size);

    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }

    scanf("%d", &q_size);
    
    for(i=0;i<q_size;i++){
        scanf("%d %d", &q_start, &q_end);
        
        sum = 0;
        for(int j=q_start-1;j<=q_end-1;j++){
            sum += arr[j];
        } 
        sum_arr[i] = sum;
    }
    for(i=0;i<q_size;i++){
        printf("%d\n",sum_arr[i]);
    }
}