#include <stdio.h>

/* 
    부분합 이용하여 풀어야 함. 안 그러면 시간초과
    for문 1번으로 풀 수 있음
    함수 P_SUM[N]={...} 입력받을 때마다 더한 값을 배열에 저장
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