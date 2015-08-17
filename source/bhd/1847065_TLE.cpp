#include <stdio.h>
 
int N, cnt;
int arr[88888];
 
int main()
{
    scanf("%d", &N);
 
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
 
    for (int i = 0; i < N; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (arr[i] <= arr[j])
                break;
            else cnt++;
        }
    }
 
    printf("%d\n", cnt);
 
    return 0;
}
