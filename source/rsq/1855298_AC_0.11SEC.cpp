#include <stdio.h>
#include <stdlib.h>
int main() {
        int array_size;
        int* array;
        int arr_sum[100000]={0};

        scanf("%d",&array_size);
        array = (int *)malloc(array_size*sizeof(int));
        for(int i=0;i<array_size;i++) {
                scanf("%d",&array[i]);
        }
        for(int i=0;i<array_size;i++) {
                if (i==0) {
                        arr_sum[i]=array[0];
                } else {
                        arr_sum[i]=arr_sum[i-1]+array[i];
                }
        }
        int q_size;
        scanf("%d",&q_size);
        for(int i=0;i<q_size;i++) {
                int start,end;
                scanf("%d %d",&start,&end);
                if(1==start) {
                        printf("%d\n", arr_sum[end-1]);
                } else {
                        printf("%d\n", arr_sum[end-1]-arr_sum[start-2]);
                }
        }


        return 0;
}
