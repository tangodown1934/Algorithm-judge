#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <functional>

using namespace std;

int main(void)
{
    int N, K;
    cin >> N >> K;
    
    if(K == 0)
    {
        for(int i = 0; i < N; i++)
            cout << 0;
        cout << endl;
        
        return 0;
    }
    
    int count = 0;
    vector<bool> checklist(N);
    fill(checklist.begin(), checklist.end(), false);
    
    function<void(int)> Recursive = [&](int curpos)
    {
        if(count == K)
        {
            for(int i = 0; i < N; i++)
                cout << checklist[i];
            cout << endl;
            
            return;
        }
        
        for(int i = curpos + 1; i < N; i++)
        {
            count++;
            checklist[i] = true;
            Recursive(i);
            checklist[i] = false;
            count--;
        }
    };
    
    for(int i = 0; i < N - K + 1; i++)
    {
        count++;
        checklist[i] = true;
        Recursive(i);
        checklist[i] = false;
        count--;
    }
    
    return 0;
}
