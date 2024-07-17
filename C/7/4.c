/*Напиши програма во која дефинираш функција nzd за пресметување на најголемиот заеднички делител на два броја.*/
#include <stdio.h>

int nzd(int num1, int num2);

int main()
{
    int num1, num2;
    printf("Vnesi dva celi broevi:");
    scanf("%d %d", &num1, &num2);
    printf("NZD na %d i %d e %d\n", num1, num2, nzd(num1, num2));

    return 0;
}

int nzd(int num1, int num2){
    int i, nzd;
    for(i = 1; i <= num1 && i <= num2; i++){
        if(num1 % i == 0 && num2 % i == 0)
            nzd = i;
    }

    return nzd;
}
