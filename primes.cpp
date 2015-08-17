#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>

using namespace std;

void inputfunc(void);
void process(int num1, int num2);

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
    //Get two numbers
    int num1, num2;
    cin >> num1 >> num2;
    
    process(num1, num2);
}

void process(int num1, int num2)
{
    //Calculate Prime Numbers
    vector<bool> PrimeCheck(10001);
    fill(PrimeCheck.begin(), PrimeCheck.end(), true);
    
    PrimeCheck[0] = false;
    PrimeCheck[1] = false;
    PrimeCheck[2] = true;
    
    for(int i = 2; i <= 100; i++)
    {
        if(PrimeCheck[i] == false)
            continue;
        
        for(int j = i; i * j <= 10000; j++)
        {
            PrimeCheck[i * j] = false;
        }
    }
    
    //Create stack and push initial number
    queue< pair<int, int> > List;
    List.push(pair<int, int>(num1, 0));
    
    //Create checklist and initialize all elements to false
    vector<bool> checklist(10001);
    fill(checklist.begin(), checklist.end(), false);
    
    int minCount = INT_MAX;
    while(!List.empty())
    {
        //Get number from Queue
        int tgNum = List.front().first;
        int tgCount = List.front().second;
        
        //delete front element from queue
        List.pop();
        
        //If this number already checked, skip.
        if(checklist[tgNum])
            continue;
        //mark this number.
        checklist[tgNum] = true;
        
        //If target number found, update mininum value.
        if(tgNum == num2)
        {
            minCount = min(minCount, tgCount);
            continue;
        }
        
        char num_to_str[5];
        
        //change each position's number, and check if it is a prime number. If true, push into queue.
        memset(num_to_str, 0, sizeof(char) * 5);
        sprintf(num_to_str, "%d", tgNum);
        for(int i = '1'; i <= '9'; i++)
        {
            num_to_str[0] = i;
            int nextNum = atoi(num_to_str);
            if(PrimeCheck[nextNum] && !checklist[nextNum])
                List.push(pair<int, int>(nextNum, tgCount + 1));
        }
        
        memset(num_to_str, 0, sizeof(char) * 5);
        sprintf(num_to_str, "%d", tgNum);
        for(int i = '0'; i <= '9'; i++)
        {
            num_to_str[1] = i;
            int nextNum = atoi(num_to_str);
            if(PrimeCheck[nextNum] && !checklist[nextNum])
                List.push(pair<int, int>(nextNum, tgCount + 1));
        }
        
        memset(num_to_str, 0, sizeof(char) * 5);
        sprintf(num_to_str, "%d", tgNum);
        for(int i = '0'; i <= '9'; i++)
        {
            num_to_str[2] = i;
            int nextNum = atoi(num_to_str);
            if(PrimeCheck[nextNum] && !checklist[nextNum])
                List.push(pair<int, int>(nextNum, tgCount + 1));
        }
        
        memset(num_to_str, 0, sizeof(char) * 5);
        sprintf(num_to_str, "%d", tgNum);
        for(int i = '0'; i <= '9'; i++)
        {
            num_to_str[3] = i;
            int nextNum = atoi(num_to_str);
            if(PrimeCheck[nextNum] && !checklist[nextNum])
                List.push(pair<int, int>(nextNum, tgCount + 1));
        }
    }
    
    cout << minCount << endl;
}