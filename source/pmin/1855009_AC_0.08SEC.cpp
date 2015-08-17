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

int main(void)
{
    int N;
    cin >> N;
    
    int min = 10000;
    
    int *Array = new int[N];
    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        
        if(num < min)
            min = num;
        
        Array[i] = num;
    }
    
    for(int i = 0; i < N; i++)
    {
        if(Array[i] == min)
            cout << i + 1 << " ";
    }
    cout << endl;
    
    return 0;
}
