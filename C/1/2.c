/*Напиши програм кој внесува 4 цели броја и ја испечатува нивната сума.*/
#include <stdio.h>

int main(){
    int num1, num2, num3, num4;
    printf("Vnesi cetiri celi broevi\n");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);
    printf("Sumata e %d\n", num1 + num2 + num3 + num4);
    return 0;
}
