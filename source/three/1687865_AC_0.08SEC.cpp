#include<stdio.h>

int main()
{
int num1, num2;
scanf("%d %d", &num1, &num2);

printf("%d\n%d\n%d\n%d\n", num1*((num2%100)%10), num1*((num2%100)/10), num1*(num2/100), num1*((num2%100)%10) + num1*((num2%100)/10)*10 + num1*(num2/100)*100);

return 0;
}