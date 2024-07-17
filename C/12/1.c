/*Само со користење на операторот за шифтирање да се напише функција mnoziSoStepenOdDva која зема два целобројни аргументи: broj и stepen и ја
 * пресметува следната вредност:
broj * 2^stepen;
*/
#include <stdio.h>

int mnoziSoStepenOdDva(int broj, int stepen);

int main()
{
    int broj, stepen;
    printf("Vnesi broj:\n");
    scanf("%d", &broj);
    printf("Vnesi stepen:\n");
    scanf("%d", &stepen);
    printf("%d * 2 ^ %d e %d", broj, stepen, mnoziSoStepenOdDva(broj, stepen));

    return 0;
}

int mnoziSoStepenOdDva(int broj, int stepen){
    return broj << stepen;
}
