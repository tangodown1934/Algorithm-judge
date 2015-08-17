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
    int N;
    cin >> N;
    
    function<void (int)> Recursive = [&](int N)
    {
        if(N > 0)
        {
            Recursive(N - 1);
            cout << N;
            Recursive(N - 1);
        }
    };
    
    Recursive(N);
    cout << endl;
    
    return 0;
}
