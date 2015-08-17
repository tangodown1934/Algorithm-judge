#include <stdio.h>
#include <stdlib.h>

int main() {


        int number_cows;
        scanf("%d",&number_cows);

        int *cows;
        cows = (int *)malloc(number_cows*sizeof(int));

        for(int itr=0;itr<number_cows;itr++) {
                scanf("%d",&cows[itr]);
        }

        int count=0;
        for(int i=0;i<number_cows;i++) {
                int eye=cows[i];
                for(int j=i+1;cows[j]<eye;j++) {
                        count++;
                }
        }
        printf("%d\n",count);

        return 0;
}