#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
 
int main()
{
    int endNum;
    int ssangNum;
    int arr[100000][2];
    int queue[10000];
    int queueIndex = 0;
    int front = 0;
    int rear = 1;
    int temp[100000] = { 0 };
 
    temp[1] = 1;
    queue[queueIndex] = 1;
 
    scanf("%d", &endNum);
    scanf("%d", &ssangNum);
    for (int i = 0; i < ssangNum; i++){
        scanf("%d %d", &arr[i][0], &arr[i][1]);
        if (arr[i][0] == 1){
            queue[++queueIndex] = arr[i][1];
            temp[arr[i][1]] = 1;
            rear = queueIndex + 1;
        }
        else if (arr[i][1] == 1){
            queue[++queueIndex] = arr[i][0];
            temp[arr[i][0]] = 1;
            rear = queueIndex + 1;
        }
    }
 
    for (int i = front; i < rear; i++){
        for (int j = 0; j < ssangNum; j++){
            if (queue[i] == arr[j][0] && temp[arr[j][1]] == 0){
                queue[++queueIndex] = arr[j][1];
                temp[arr[j][1]] = 1;
            }
            if (queue[i] == arr[j][1] && temp[arr[j][0]] == 0){
                queue[++queueIndex] = arr[j][0];
                temp[arr[j][0]] = 1;
            }
        }
        if (i == rear - 1){
            front = rear;
            rear = queueIndex+1;
        }
    }
 
    /*for (int i = 1; i <= queueIndex; i++){
        printf("%d\n", queue[i]);
    }*/
    printf("%d\n", queueIndex);
 
    return 0;
}
