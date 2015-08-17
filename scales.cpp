#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void process(int N, vector<int> &List);
void DFS(int N, vector<int> &List, int current_pos, int &count, int &current_sum, int sum);

int main(void)
{
    int N;
    cin >> N;
    
    vector<int> List(N);
    for(int i = 0; i < N; i++)
        cin >> List[i];
    
    sort(List.begin(), List.end());
    
    process(N, List);
    
    return 0;
}

void process(int N, vector<int> &List)
{
    int sum = 0;
    for(int i = 0; i < List.size(); i++)
        sum += List[i];
    
    if(sum % 2 != 0)
    {
        cout << "impossible" << endl;
        return;
    }
    
    vector<int> partial_sum_list(N);
    fill(partial_sum_list.begin(), partial_sum_list.end(), 0);
    partial_sum_list[0] = List[0];
    for(int i = 1; i < N; i++)
        partial_sum_list[i] += List[i] + partial_sum_list[i - 1];
    
    int count = 0;
    int current_sum = 0;
    for(int i = 0; i < N; i++)
    {
        if(partial_sum_list[i] > sum / 2)
            break;
        
        current_sum += List[i];
        DFS(N, List, i, count, current_sum, sum);
        current_sum -= List[i];
    }
    
    if(count == 0)
        cout << "impossible" << endl;
    else
        cout << count << endl;
}

void DFS(int N, vector<int> &List, int current_pos, int &count, int &current_sum, int sum)
{
    if(current_sum == sum / 2)
    {
        count++;
        return;
    }
    else if(current_sum > sum / 2)
        return;
    
    for(int i = current_pos + 1; i < N; i++)
    {
        current_sum += List[i];
        DFS(N, List, i, count, current_sum, sum);
        current_sum -= List[i];
    }
}
