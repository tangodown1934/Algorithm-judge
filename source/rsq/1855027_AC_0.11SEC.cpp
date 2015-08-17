#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int arraylist[100001];

int main(void)
{
    int N;
    scanf("%d", &N);;
    
    for(int i = 1; i <= N; i++)
    {
        int num;
        scanf("%d", &num);
        
        arraylist[i] = num;
    }
    
    for(int i = 1; i <= N; i++)
    {
        arraylist[i] += arraylist[i - 1];
    }
    
    int query;
    scanf("%d", &query);
    
    for(int i = 0; i < query; i++)
    {
        int start, end;
        scanf("%d %d", &start, &end);
        printf("%d\n", arraylist[end] - arraylist[start - 1]);
    }
    
    return 0;
}
