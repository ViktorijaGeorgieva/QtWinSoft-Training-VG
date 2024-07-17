/*Напиши програм кој вчитува три цели броја и пресметува нивна целобројна средна вредност, сума и производ.*/
#include <stdio.h>

int main()
{
    int num1, num2, num3;
    printf("Vnesi tri celi broevi\n");
    scanf("%d %d %d", &num1, &num2, &num3);
    printf("Sredna vrednost:%d\n", (num1 + num2 + num3) / 3);
    printf("Suma:%d\n", num1 + num2 + num3);
    printf("Proizvod:%d\n", num1 * num2 * num3);
    return 0;
}
