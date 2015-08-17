#include <iostream>
#include <vector>

using namespace std;

bool global_force_return;

void inputfunc(void);
void process_Combination(int N, int R, int target, int &count, vector<bool> &checklist, int current, int depth);
void process_Permutation(int N, int R, int target, int &count, vector<bool> &checklist, vector<int> pushlist);

int main(void)
{
    int T;
    cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        cout << "#testcase" << i + 1 << endl;
        inputfunc();
    }
    
    return 0;
}

void inputfunc(void)
{
    int N, R;
    cin >> N >> R;
    
    int P, Q;
    cin >> P >> Q;
    
    
    int count_V = 0;
    vector<bool> checklist(N);
    fill(checklist.begin(), checklist.end(), false);
    vector<int> pushlist;
    global_force_return = false;
    for(int i = 0; i < N; i++)
    {
        pushlist.push_back(i);
        checklist[i] = true;
        if(global_force_return) break;
        
        process_Permutation(N, R, P, count_V, checklist, pushlist);
        
        if(global_force_return) break;
        checklist[i] = false;
        pushlist.pop_back();
    }
    
    int count_C = 0;
    fill(checklist.begin(), checklist.end(), false);
    global_force_return = false;
    for(int i = 0; i < N; i++)
    {
        checklist[i] = true;
        if(global_force_return) break;
        
        process_Combination(N, R, Q, count_C, checklist, i, 1);
        
        if(global_force_return) break;
        checklist[i] = false;
    }
}

void process_Permutation(int N, int R, int target, int &count, vector<bool> &checklist, vector<int> pushlist)
{
    if(pushlist.size() == R)
    {
        count++;
        if(count == target)
        {
            for(int i = 0; i < pushlist.size(); i++)
                cout << (char)(pushlist[i] + 'A');
            cout << endl;
            
            global_force_return = true;
        }
        
        return;
    }
    
    for(int i = 0; i < N; i++)
    {
        if(checklist[i] == true)
            continue;
        
        pushlist.push_back(i);
        checklist[i] = true;
        if(global_force_return) return;
        
        process_Permutation(N, R, target, count, checklist, pushlist);
        
        if(global_force_return) return;
        checklist[i] = false;
        pushlist.pop_back();
    }
}

void process_Combination(int N, int R, int target, int &count, vector<bool> &checklist, int current, int depth)
{
    if(depth == R)
    {
        count++;
        if(count == target)
        {
            for(int i = 0; i < N; i++)
                if(checklist[i])
                    cout << (char)(i + 'A');
            cout << endl;
            
            global_force_return = true;
        }
        
        return;
    }
    
    for(int i = current + 1; i < N; i++)
    {
        checklist[i] = true;
        if(global_force_return) return;
        
        process_Combination(N, R, target, count, checklist, i, depth + 1);
        
        if(global_force_return) return;
        checklist[i] = false;
    }
}
