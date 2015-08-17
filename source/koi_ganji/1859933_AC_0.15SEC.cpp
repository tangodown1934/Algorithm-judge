#include <stdio.h>
int main() {
int a;
scanf("%d",&a);
a-=4;
int b=a%12+65;
int c=a%10;
printf("%c%d",b,c);
}
