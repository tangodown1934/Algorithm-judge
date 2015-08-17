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

char str[100000000];

int main(void)
{
    char *p = &str[0];
    
    int count = 1;
    while(true)
    {
        int size = sprintf(p, "%d", count);
        p += size;
        count++;
        
        if(p - &str[0] > 1000000)
            break;
    }
    
    int N;
    scanf("%d", &N);
    printf("%c\n", str[N - 1]);
    
    return 0;
}
