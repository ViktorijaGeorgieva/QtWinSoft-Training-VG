/*Напиши рекурзивна верзија на програма која за внесено n повикува функција dzvezdi со параметар n која во зависност од n испечатува ѕвезди на
 * следниот начин:
    Vnesi broj na dzvezdi (n): 5
    Se dobiva:
    * * * * *
    * * * *
    * * *
    * *
    *
*/
#include <stdio.h>

int dzvezdi(int n);

int main()
{
    int n;
    printf("Vnesi n:");
    scanf("%d", &n);
    dzvezdi(n);

    return 0;
}

int dzvezdi(int n){
    int i;

    if(n == 0)
        return;

    for(i = 0; i < n; i++){
        printf("* ");
    }

    printf("\n");

    dzvezdi(n-1);
}
