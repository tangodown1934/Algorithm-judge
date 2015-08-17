#include <stdio.h>
#include <stdlib.h>

int main() {

        int size;
        int* arr;
        scanf("%d",&size);

        arr = (int *)malloc(size*sizeof(int));
        for (int i=0;i<size;i++) {
                scanf("%d",&arr[i]);
        }
        int min=arr[0];
        for(int i=0;i<size;i++) {
                if(min>arr[i]) {
                        min=arr[i];
                }
        }
        for(int i=0;i<size;i++) {
                if(min==arr[i]) {
                        printf("%d ",i+1);
                }
        }


        return 0;
}