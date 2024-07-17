/*Една голема хемиска компанија ги плаќа своите продавачи делумно и на процент. Продавачите земаат плата од 200 евра плус 9% од вкупната нивна
 * продажба за тој месец. На пример, ако некој продавач продал роба вредна 5000 евра, тогаш добива 200 евра плус 9% од 5000, значи вкупно 650 евра.
 *  Напиши програма која за внесен месечен промет му ја пресметува платата на вработениот. Пример:
Vnesi promet vo evra (-1 za kraj): 5000.00
Platata e: 650.00 evra

Vnesi promet vo evra (-1 za kraj): 1234.56
Platata e: 311.11 evra

Vnesi promet vo evra (-1 za kraj): 1088.89
Platata e: 298.00 evra
Vnesi promet vo evra (-1 za kraj): -1
*/
#include <stdio.h>

int main()
{
    float salary = 200.00, monthlyProfit = 0.00;

    while(monthlyProfit != -1){
        printf("Vnesi promet vo evra: ");
        scanf("%f", &monthlyProfit);
        if(monthlyProfit == -1)
            break;
        salary += (monthlyProfit * 0.09);
        printf("Platata e %.2f\n", salary);
        salary = 200.00;
    }

    return 0;
}
