/*2.	Напиши програма која вчитува датуми во облик gg/mm/dd, gg-mm-dd и gg+mm+dd и ги испечаува така да наместо бројот на месецот се испечати
 *  имато на месецот.
Пример:
Vnesi datum: 2005+06+01
Vneseniot datum e 1 juni 2005 godina.
*/
#include <stdio.h>

int main()
{
    int day, month, year;
    printf("Vnesi datum: ");
    scanf("%d%*c%d%*c%d", &year, &month, &day);

    switch(month){
    case 1:
        printf("Vneseniot datum e %d januari %d godina.\n", day, year);
        break;
    case 2:
        printf("Vneseniot datum e %d fevruari %d godina.\n", day, year);
        break;
    case 3:
        printf("Vneseniot datum e %d mart %d godina.\n", day, year);
        break;
    case 4:
        printf("Vneseniot datum e %d april %d godina.\n", day, year);
        break;
    case 5:
        printf("Vneseniot datum e %d maj %d godina.\n", day, year);
        break;
    case 6:
        printf("Vneseniot datum e %d juni %d godina.\n", day, year);
        break;
    case 7:
        printf("Vneseniot datum e %d juli %d godina.\n", day, year);
        break;
    case 8:
        printf("Vneseniot datum e %d avgust %d godina.\n", day, year);
        break;
    case 9:
        printf("Vneseniot datum e %d septemvri %d godina.\n", day, year);
        break;
    case 10:
        printf("Vneseniot datum e %d oktomvri %d godina.\n", day, year);
        break;
    case 11:
        printf("Vneseniot datum e %d noemvri %d godina.\n", day, year);
        break;
    case 12:
        printf("Vneseniot datum e %d dekemvri %d godina.\n", day, year);
        break;
    default:
        break;
    }

    return 0;
}
