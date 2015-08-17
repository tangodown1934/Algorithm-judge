#include<stdio.h>

int main()
{
int num;
scanf("%d", &num);
num = 1000-num;
printf("%d %d %d\n", num/100, (num%100)/50, (num%100)%50/10);

return 0;
}