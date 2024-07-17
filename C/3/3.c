/*Обидете се со спецификаторот за конверзија %d да испечатите букви на следниот начин:
printf(“%d”, ‘A’)
Што се случува кога се печатат следните карактери: b  c  0  1  2  $  *  +  / и празно место?
*/
#include <stdio.h>

int main()
{
    /*Gi pecati ASCII kodovite na karakterite*/
    printf("%d %d %d %d %d %d %d %d %d %d %d\n", 'A', 'b', 'c', '0', '1', '$', '*', '+', '/', ' ');
    return 0;
}
