#include <stdio.h>
#include <stdlib.h>

int main() {


        int number_cows;
        scanf("%d",&number_cows);

        int *cows;
        cows = (int *)malloc(number_cows*sizeof(int));

        int itr=0;
        for(itr=0;itr<number_cows;itr++) {
                scanf("%d",&cows[itr]);
        }

        int i,j;
        int count=0;
        for(i=0;i<number_cows;i++) {
                int eye=cows[i];
                for(j=i+1;cows[j]<eye;j++) {
                        count++;
                }
        }
        printf("%d\n",count);

        return 0;
}