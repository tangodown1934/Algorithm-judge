#include <stdio.h>

int main(){
    int size=10, modNUm = 42;
    int i, flag=0,count=0;
    int arr[11], arrMo[11];

    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
        arrMo[i] = arr[i]%42;
    }

    for(i=0;i<size;i++){
        flag = 1; 
        for(int j=i+1;j<size;j++){
            if(arrMo[i] == arrMo[j])
               flag = 0; 
        }
        if(flag==1)
            count++;
    }
    printf("%d", count);
}
