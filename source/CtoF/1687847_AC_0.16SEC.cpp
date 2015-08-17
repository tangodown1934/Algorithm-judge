#include<stdio.h>

int main()
{
int num;
double result;

scanf("%d", &num);
result = (double)(num)*9/5+32;
printf("%.1lf\n", result);

return 0;
}