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

bool arraylist[42];

int main(void)
{
    for(int i = 0; i < 10; i++)
    {
        int num;
        scanf("%d", &num);
        
        int modular = num % 42;
        arraylist[modular] = true;
    }
    
    int count = 0;
    
    for(int i = 0; i < 42; i++)
    {
        if(arraylist[i])
            count++;
    }
    
    printf("%d\n", count);
    
    return 0;
}
