#include <iostream>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void process(int N, vector< vector<int> > &Grid);
bool isPink(pair<int, int> start, pair<int, int> end, vector< vector<int> > &Grid);
bool isWhite(pair<int, int> start, pair<int, int> end, vector< vector<int> > &Grid);
void DFS(int N, vector< vector<int> > &Grid, pair<int, int> start, pair<int, int> end, int &whiteCount, int &pinkCount);

int main(void)
{
    int N;
    cin >> N;
    
    vector< vector<int> > Grid(N + 1);
    for(int i = 1; i <= N; i++)
    {
        Grid[i].resize(N + 1);
        for(int j = 1; j <= N; j++)
            cin >> Grid[i][j];
    }
    
    process(N, Grid);
    
    return 0;
}

bool isPink(pair<int, int> start, pair<int, int> end, vector< vector<int> > &Grid)
{
    for(int i = start.second; i <= end.second; i++)
    {
        for(int j = start.first; j <= end.first; j++)
        {
            if(Grid[i][j] != 1)
                return false;
        }
    }
    
    return true;
}

bool isWhite(pair<int, int> start, pair<int, int> end, vector< vector<int> > &Grid)
{
    for(int i = start.second; i <= end.second; i++)
    {
        for(int j = start.first; j <= end.first; j++)
        {
            if(Grid[i][j] != 0)
                return false;
        }
    }
    
    return true;
}

void process(int N, vector< vector<int> > &Grid)
{
    int whiteCount = 0;
    int pinkCount = 0;
    
    if(isWhite(pair<int, int>(1, 1), pair<int, int>(N, N), Grid))
        whiteCount++;
    else if(isPink(pair<int, int>(1, 1), pair<int, int>(N, N), Grid))
        pinkCount++;
    else
    {
        DFS(N, Grid, pair<int, int>(1, 1), pair<int, int>(N / 2, N / 2), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(N / 2 + 1, 1), pair<int, int>(N, N / 2), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(1, N / 2 + 1), pair<int, int>(N / 2, N), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(N / 2 + 1, N / 2 + 1), pair<int, int>(N, N), whiteCount, pinkCount);
    }
    
    cout << whiteCount << endl;
    cout << pinkCount << endl;
}

void DFS(int N, vector< vector<int> > &Grid, pair<int, int> start, pair<int, int> end, int &whiteCount, int &pinkCount)
{
    if(isWhite(start, end, Grid))
    {
        whiteCount++;
        return;
    }
    else if(isPink(start, end, Grid))
    {
        pinkCount++;
        return;
    }
    else
    {
        int midX = (start.first + end.first) / 2;
        int midY = (start.second + end.second) / 2;
        pair<int, int> mid(midX, midY);
        
        DFS(N, Grid, pair<int, int>(start.first, start.second), pair<int, int>(mid.first, mid.second), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(mid.first + 1, start.second), pair<int, int>(end.first, mid.second), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(start.first, mid.second + 1), pair<int, int>(mid.first, end.second), whiteCount, pinkCount);
        DFS(N, Grid, pair<int, int>(mid.first + 1, mid.second + 1), pair<int, int>(end.first, end.second), whiteCount, pinkCount);
    }
}
