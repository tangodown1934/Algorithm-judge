#pragma warning(disable:4996)
#include <stdio.h>
 
#define SIZE 11
#define QSIZE 1111111
 
char chess[SIZE][SIZE];
int color[SIZE][SIZE];
int visited[SIZE][SIZE];
 
int qX[QSIZE];
int qY[QSIZE];
int qColor[QSIZE];
int front, rear;
 
int pX[] = { 0, -1, 0, +1 };
int pY[] = { -1, 0, +1, 0 };
int cnt;
 
void print()
{
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            printf("%d ", color[i][j]);
        }
        printf("\n");
    }
}
 
void bfs()
{
    int x, y, c;
    int mX, mY;
    int i;
 
    //init
    front = rear = 0;
    qX[rear] = 0; qY[rear] = 0; qColor[rear] = 1;
    rear++;
    while (front != rear)
    {
        // pop
        x = qX[front]; 
        y = qY[front]; 
        c = qColor[front];
        front++;
 
         
        color[x][y] = c; // 색칠 (방문처리)
        if (chess[x][y] == 'F' && c == 1 && visited[x][y]==0){
            //print();
            cnt++;
            visited[x][y] = 1;
        }
 
        for (i = 0; i < 4; i++)
        {
            mX = x + pX[i]; mY = y + pY[i];
 
            if (mX >= 0 && mX < 8 && mY >= 0 && mY < 8){
                if (color[mX][mY] == 0) // 비었다면
                {
                    qX[rear] = mX;
                    qY[rear] = mY;
                    qColor[rear] = c*-1;
                    rear++;
                }
            }
        }
    }
}
 
int main()
{
    int i, j;
 
    for (i = 0; i < 8; i++){
        scanf("%s", &chess[i]);
    }
 
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            visited[i][j] = color[i][j] = 0;
        }
    }
 
    cnt = 0;
    bfs();
    // print();
    printf("%d\n", cnt);
 
    return 0;
}