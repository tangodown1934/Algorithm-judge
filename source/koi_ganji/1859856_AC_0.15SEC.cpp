#include <stdio.h>

int main() {
        int input;
        scanf("%d",&input);

        char arr[3];

        arr[1]=((input-4)%10)+48;
        arr[2]='\0';
        arr[0]=((input-4)%12)+65;

        printf("%s\n",arr);
}
