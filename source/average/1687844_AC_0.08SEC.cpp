#include<stdio.h>

int main()
{
int num[4];
double result;

scanf("%d %d %d %d", &num[0], &num[1], &num[2], &num[3]);
result = (double)(num[0]+num[1]+num[2]+num[3])/4;
printf("%.2lf\n", result);

return 0;
}