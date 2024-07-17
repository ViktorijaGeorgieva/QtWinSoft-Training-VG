/*Една стоковна куќа продава 5 производи чии цени се дадени во долната табела
Производ број	Цена
1	50.5
2	45.6
3	32.8
4	65.3
5	20.0
Да се напише програм кој чита серија од парови броеви за:
а) број на производ
б) количина продадена во текот на денот
Програмот треба да ја користи switch наредбата за да ја одреди цената за секој  производ. Програмот треба да ја пресмета и испечати вкупната продадена
вредност за секој од производите посебно, како и вкупната сума за сите производи продадени во текот на денот.
*/
#include <stdio.h>

int main()
{
    int productNumber, numberOfSoldProducts, counter = 0, productNumbers[5];
    float price, total = 0, totalSalesPerProduct[5];

    while(counter < 5){
        printf("Vnesi broj na proizvod i kolicina prodadena vo denot\n");
        scanf("%d %d", &productNumber, &numberOfSoldProducts);

        switch (productNumber) {
        case 1:
            price = 50.5;
            break;
        case 2:
            price = 45.6;
            break;
        case 3:
            price = 32.8;
            break;
        case 4:
            price = 65.3;
            break;
        case 5:
            price = 20.0;
            break;
        default:
            printf("Ne postoi proizvod so reden broj %d\n", productNumber);
            break;
        }
        productNumbers[counter] = productNumber;
        totalSalesPerProduct[counter] = price * numberOfSoldProducts;
        total += totalSalesPerProduct[counter];
        counter++;
    }

    counter = 0;

    while (counter < 5) {
        printf("Proizvodot so reden broj %d ima vkupna prodadena vrednost %.1f\n", productNumbers[counter], totalSalesPerProduct[counter]);
        counter++;
    }

    printf("Vkupnata suma e %.1f", total);

    return 0;
}
