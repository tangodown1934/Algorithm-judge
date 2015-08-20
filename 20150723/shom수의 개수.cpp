#pragma warning(disable:4996)
#include <stdio.h>
 
#define SIZE 111111
 
long long int q[SIZE];
 
int main()
{
    long long int A, B;
    int front, rear;
    int cnt;
 
    scanf("%lld %lld", &A, &B);
 
    front = rear = 0;
    q[rear++] = 4;
    q[rear++] = 7;
 
    cnt = 0;
    while (q[front] <= B){
        if (q[front] >= A)
            cnt++;
 
        q[rear++] = (q[front] * 10) + 4;
        q[rear++] = (q[front] * 10) + 7;
        front++;
    }
    printf("%d\n", cnt);
 
    return 0;
}