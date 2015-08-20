#pragma warning(disable:4996)
#include <stdio.h>
 
#define SIZE 111
 
int N, S, M;
int vol[SIZE];
int cache[SIZE][111111];
int ans;
 
int max(int a, int b)
{
    if (a < b)
        return b;
    return a;
}
 
int sol(int idx, int sum)
{
    int i;
 
    // 기저사례
    if (sum<0 || sum>M) return -1111111; // 값을 초과한다면
    if (idx == N) return sum; // 끝까지 간경우 볼륨의 합계
 
    int& ret = cache[idx][sum];
    if (ret != -1) return ret;
 
    ret = max(sol(idx + 1, sum - vol[idx]), sol(idx + 1, sum + vol[idx]));
 
    return ret;
}
 
int main()
{
    int i, j;
 
    scanf("%d %d %d", &N, &S, &M);
 
    // input , init
    for (i = 0; i < N; i++){
        scanf("%d", &vol[i]);
    }
    for (i = 0; i < SIZE; i++)
        for (j = 0; j < 111111; j++)
            cache[i][j] = -1;
 
    ans = sol(0, S);
    if (ans < 0) ans = -1;
    printf("%d\n", ans);
 
    return 0;
}