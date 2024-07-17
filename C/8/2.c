/*Прости броеви се броеви кои се деливи само со себе си и со бројот 1. Напиши програм кој внесува n елементи во низа. Да се овозможи функционалност
 * да имаме променлив број на елементи во низата. Во почетокот сите елементи да се иницијализираат на 1. Потоа да се напише функција prosti која секој
 * елемент од низата чиј индекс е прост број, го поставува на 0. На крај од така добиената низа да се најде начин да се испечатат простите броеви до
 * n.*/
#include <stdio.h>

void prosti(int n, int numbers[]);

int main()
{
    int n, i;
    printf("Vnesi n:");
    scanf("%d", &n);
    int numbers[n];
    for(i = 0; i < n; i++){
        numbers[i] = 1;
    }
    prosti(n, numbers);
    return 0;
}

void prosti(int n, int numbers[]){
    int i, j, prost;
    for(i = 2; i <= n; i++){
        prost = 1;
        for(j = 2; j * j <= i; j++){
            if(i % j == 0){
                prost = 0;
                break;
            }
        }
        if(prost){
            numbers[i] = 0;
        }
    }
    printf("Prosti broevi do %d: ", n);
    for(i = 2; i <= n; i++){
        if(numbers[i] == 0)
            printf("%d ", i);
    }
    printf("\n");
}
