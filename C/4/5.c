/*Напиши програма која за внесени десет броја, го пресметува нивниот производ.*/
#include <stdio.h>

int main()
{
    int i = 0, num, product = 1;
    printf("Vnesi 10 broevi\n");
    while(i < 10){
        scanf("%d", &num);
        product *= num;
        i++;
    }
    printf("Nivniot proizvod e %d\n", product);
    return 0;
}
