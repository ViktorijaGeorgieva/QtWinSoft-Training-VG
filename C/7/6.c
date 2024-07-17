/*Напиши рекурзивна верзија на функцијата за пресметување најголем заеднички делител.*/
#include <stdio.h>

int nzd_recursive(int num1, int num2);

int main()
{
    int num1, num2;
    printf("Vnesi dva celi broevi:");
    scanf("%d %d", &num1, &num2);
    printf("NZD na %d i %d e %d\n", num1, num2, nzd_recursive(num1, num2));

    return 0;
}

int nzd_recursive(int num1, int num2){
    if(num2 == 0)
        return num1;

    return nzd_recursive(num2, num1 % num2);
}
