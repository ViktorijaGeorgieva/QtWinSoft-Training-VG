/*Да се претстави природниот број n како производ од прости множители. (n=p1k1p2k2...prkr , каде што p1, p2, ..., pr се прости броеви, а
 * k1, k2, . . . , kr се природни броеви.)*/
#include <stdio.h>
#include <math.h>

void prostiMnoziteli(int n);

int main()
{
    int n;
    printf("Vnesi broj:");
    scanf("%d", &n);
    prostiMnoziteli(n);
    return 0;
}

void prostiMnoziteli(int n){
    int i;
    while (n % 2 == 0) {
        printf("2 ");
        n /= 2;
    }
    for(i = 3; i <= sqrt(n); i += 2){
        while(n % i == 0){
            printf("%d ", i);
            n /= i;
        }
    }
    if(n > 2){
        printf("%d ", n);
    }
    printf("\n");
}
