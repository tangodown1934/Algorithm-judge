#include<stdio.h>

int main()
{
int num1, num2;
double result;
scanf("%d %d", &num1, &num2);
result = (double)(num1 * num2)/2;
printf("%.2lf\n", result);

return 0;
}