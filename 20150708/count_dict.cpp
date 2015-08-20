#include <stdio.h>

/* 
    부분합 이용하여 풀어야 함. 안 그러면 시간초과
    for문 1번으로 풀 수 있음
    함수 P_SUM[N]={...} 입력받을 때마다 더한 값을 배열에 저장
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
