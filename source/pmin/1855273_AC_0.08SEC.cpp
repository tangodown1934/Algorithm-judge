#include <stdio.h>

int main(){
    int size, min, i;
    int arr[100];

    scanf("%d", &size);
    for(i=0;i<size;i++){
        scanf("%d", &arr[i]);
    }
    min = arr[0];
    for(i=0;i<size;i++){
        if(arr[i]<min){
           min = arr[i]; 
        }
    }
    for(i=0;i<size;i++){
        if(arr[i]==min){
            printf("%d ", i+1);
        }
    }
}