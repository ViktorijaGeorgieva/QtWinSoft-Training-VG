/*Во примерот p03_01.c, во наредбата printf наместо спецификаторот за конверзија  %f, поставете го спецификаторот %d. Што се случува и зошто?*/
#include <stdio.h>

float result;

int main()
{
    result = 7.0 / 22.0;
    printf("Rezultatot e %d\n", result);
    /*Se pecati random broj, bidejki so %d ocekuva int vrednost a result e float*/
    return (0);
}
