#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
 
void process(int &N, int *tower_height);
void inputfunc(void);

int main(void)
{
    int T = 1;
    //cin >> T;
    
    for(int i = 0; i < T; i++)
    {
        //cout << "#testcase" << i + 1 << endl;
        inputfunc();
    }
    
    return 0;
}

void inputfunc(void)
{
    int N;
    cin >> N;
    
    int *tower_list = new int[N];
    for(int i = 0; i < N; i++)
        cin >> tower_list[i];
    
    process(N, tower_list);
}

void process(int &N, int *tower_height)
{
    int *tower_count = new int[N];
    fill(tower_count, tower_count + N, 0);
    
    int stack_replace[10000];
    int stack_index = -1;
    
    stack_replace[++stack_index] = N - 1;
    
    for(int i = N - 2; i >= 0; i--)
    {
        int count = 0;
        
        while(stack_index >= 0)
        {
            int height = tower_height[stack_replace[stack_index]];
            
            if(tower_height[i] > height)
            {
                count++;
                count += tower_count[stack_replace[stack_index]];
                stack_index--;
            }
            else
                break;
        }
        
        stack_replace[++stack_index] = i;
        tower_count[i] = count;
    }
    
    int sum = 0;
    for(int i = 0; i < N; i++)
        sum += tower_count[i];
    
    cout << sum << endl;
}