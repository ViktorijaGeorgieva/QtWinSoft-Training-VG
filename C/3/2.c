/*Напиши програм кој вчитува два цели броја и одредува дали се парни или непарни.*/
#include <stdio.h>

int main()
{
    int num1, num2;
    printf("Vnesi dva celi broevi\n");
    scanf("%d %d", &num1, &num2);
    if(num1 % 2 == 0){
        printf("%d e paren broj\n", num1);
    }else{
        printf("%d e neparen broj\n", num1);
    }
    if(num2 % 2 == 0){
        printf("%d e paren broj\n", num2);
    }
    else{
        printf("%d e neparen broj\n", num2);
    }
    return 0;
}
