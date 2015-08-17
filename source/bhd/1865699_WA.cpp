#include <iostream>
#include <string>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

void process(int &N, vector<int> &tower_list);

int main(void)
{
    int N;
    cin >> N;
    
    vector<int> tower_list(N);
    for(int i = 0; i < N; i++)
        cin >> tower_list[i];
    
    process(N, tower_list);
    
    return 0;
}

void process(int &N, vector<int> &tower_list)
{
    vector<int> tower_count(N);
    fill(tower_count.begin(), tower_count.end(), 0);
    
    stack< pair<int, int> > tower_stack;
    tower_stack.push(pair<int, int>(tower_list[N - 1], N - 1));
    
    for(int i = N - 2; i >= 0; i--)
    {
        int index = tower_stack.top().second;
        int height = tower_stack.top().first;
        
        while(!tower_stack.empty() && tower_list[i] > height)
        {
            tower_stack.pop();
            tower_count[i] += 1 + tower_count[index];
        }
        
        tower_stack.push(pair<int, int>(tower_list[i], i));
    }
    
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += tower_count[i];
    
    cout << sum << endl;
}