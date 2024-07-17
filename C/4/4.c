/*Напиши програма која ја пресметува сумата на броевите од 1 до десет.*/
#include <stdio.h>

int main()
{
    int i = 1, sum = 0;

    while(i <= 10){
        sum += i;
        i++;
    }
    printf("Sumata na broevite od 1 do 10 e %d\n", sum);
    return 0;
}
