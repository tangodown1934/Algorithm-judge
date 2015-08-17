#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
using namespace std;

struct location
{
    int pos;
    char type;
};

struct myPair
{
    int first;
    int second;
};

location List[100];
int List_index = -1;

void inputfunc(void);

int main(void)
{
    int T;
    //scanf("%d", &T);
    //getchar();
    
    for(int i = 0; i < T; i++)
    {
        //printf("#testcase%d\n", i + 1);
        inputfunc();
    }
    
    return 0;
}

void inputfunc(void)
{
    char str[100];
    memset(str, 0, sizeof(char) * 100);
    scanf("%s", str);
    
    myPair pairList[100];
    int where = 0;
    
    for(int i = 0; i < strlen(str); i++)
    {
        if(str[i] == '(')
        {
            location insert;
            insert.pos = i;
            insert.type = '(';
            List[++List_index] = insert;
        }
        else if(str[i] == ')')
        {
            if(List_index < 0)
            {
                printf("not match\n");
                return;
            }
            else if(List[List_index].type != '(')
            {
                printf("not match\n");
                return;
            }
            else
            {
                //printf("%d %d\n", List[List_index].pos, i);
                pairList[where].first = List[List_index].pos, pairList[where].second = i;
                where++;
                List_index--;
            }
        }
    }
    
    if(List_index >= 0)
        printf("not match\n");
    
    for(int i = 0; i < where; i++)
        printf("%d %d\n", pairList[i].first, pairList[i].second);
}