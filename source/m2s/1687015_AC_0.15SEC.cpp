#include <stdio.h>

int main()
{
int minutes;
scanf("%d", &minutes);
printf("%d minutes is %d seconds.\n", minutes, 60*minutes);
return 0;
}