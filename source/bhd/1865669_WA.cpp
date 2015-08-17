#include <stdio.h>
#include <stdlib.h>

int main() {
        int number_cows;
        scanf("%d",&number_cows);

        int *cows;
        cows = (int *)malloc(number_cows*sizeof(int));

        int itr=0;
        int array_size=0;
        int count=0;
        scanf("%d",&cows[0]);
        for(itr=1;itr<number_cows;itr++) {
                scanf("%d",&cows[itr]);
                array_size++;
                for(int i=0;i<array_size;i++) {
                        if(cows[itr]>=cows[i]) {
                                for(int j=i+1;j<array_size;j++) {
                                        cows[j-1]=cows[j];
                                }
                                array_size--;
                        }
                }
                count+=array_size;
        }

        printf("%d\n",count-1);

        return 0;
}
