#include <stdio.h>
#include <string.h>
#include <queue>
using namespace std;

#define SIZE 111111

int visit[SIZE];
int matrix[SIZE];

int delX[2] = {1, -1};
int min_num=999999, cnt;
int v1, v2;

void BFS(int start_x)
{
	queue<int> q_x;
	int cnt = 0;

	q_x.push(start_x);

	while (!q_x.empty())
	{
		int here_x = q_x.front();

		visit[start_x] = 1;

		if (here_x == v2)
		{
			//printf("도착지점 : ");
			//printf("%d\n", visit[here_x]); 
			if (min_num > visit[here_x]) min_num = visit[here_x];
		}

		//printf("위치 : %d\n", here_x);

		q_x.pop();

		for (int i = 0; i < 2; i++)
		{
			if ((!visit[here_x + delX[i]] || visit[here_x+delX[i]] > visit[here_x]+1) && (here_x + delX[i] >= 0 && here_x + delX[i] < v2+1))
			{
				visit[here_x + delX[i]] = visit[here_x] + 1;
				q_x.push(here_x + delX[i]); 
			}
		}
		if ((!visit[here_x * 2] || visit[here_x*2] > visit[here_x] + 1 ) && (here_x *2 < v2+1))
		{
			visit[here_x * 2] = visit[here_x] + 1;
			q_x.push(here_x *2);
		}
	}
}

int main()
{

	scanf("%d %d", &v1, &v2);

	BFS(v1);

	printf("%d\n", min_num-1);
	return 0;
}