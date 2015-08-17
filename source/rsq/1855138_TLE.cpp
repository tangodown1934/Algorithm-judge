#include <stdio.h>
#include <stdlib.h>

int main() {
        int array_size;
        int* array;

        scanf("%d",&array_size);
        array = (int *)malloc(array_size*sizeof(int));
        for(int i=0;i<array_size;i++) {
                scanf("%d",&array[i]);
        }
        int q_size;
        scanf("%d",&q_size);
        for(int i=0;i<q_size;i++) {
                int start,end;
                scanf("%d %d",&start,&end);
                int sum=0;
                if(start==end) {
                        sum=array[start-1];
                } else {
                        for(int j=start;j<=end;j++) {
                                sum+=array[j-1];
                        }
                }
                printf("%d\n", sum);
        }


        return 0;
}
