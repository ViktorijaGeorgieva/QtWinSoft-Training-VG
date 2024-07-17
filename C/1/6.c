/*Напиши програм кој внесува петцифрен број, ги распределува сите цифри на бројот во посебни променливи и ги печати секоја од цифрите со
 * растојание една од дуга од три празни места. */
#include <stdio.h>

int main()
{
    int num, d1, d2, d3, d4, d5;
    printf("Vnesi petcifren broj:\n");
    scanf("%d", &num);
    d5 = num % 10;
    num /= 10;
    d4 = num % 10;
    num /= 10;
    d3 = num % 10;
    num /= 10;
    d2 = num % 10;
    num /= 10;
    d1 = num % 10;
    printf("%d   %d   %d   %d   %d", d1, d2, d3, d4, d5);
    return 0;
}
