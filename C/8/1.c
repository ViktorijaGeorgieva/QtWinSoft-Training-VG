/*Напиши програм кој вчитува вредности за температури за секој ден од месецот и наоѓа средна месечна температура. Да се земе предвид дека
 *различни месеци имаат различен број на денови.*/
#include <stdio.h>

float sredna_mesecna_temperatura(int days, float temperatures[]);

int main()
{
    int month, days, i;
    float temperatures[31];
    printf("Vnesete mesec:");
    scanf("%d", &month);

    switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        days = 31;
        break;
    case 4:
    case 6:
    case 9:
    case 11:
        days = 30;
        break;
    case 2:
        days = 28;
        break;
    default:
        break;
    }
    printf("Vnesi temperaturi za sekoj den od mesecot:");
    for(i = 0; i < days; i++){
        scanf("%f", &temperatures[i]);
    }
    printf("Srednata mesecna temperatura e %.2f\n", sredna_mesecna_temperatura(days, temperatures));
    return 0;
}

float sredna_mesecna_temperatura(int days, float temperatures[]){
    int i;
    float total = 0.0;
    for(i = 0; i < days; i++){
        total += temperatures[i];
    }

    return total / days;
}
