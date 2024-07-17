/*Секоја од n бактерии се дели на две на секои i минути, додека на секои j минути изумираат x% од живите бактерии во тој момент.
 * Колку бактерии ќе има по k минути?*/
#include <stdio.h>

int main()
{
    int n, i, j, x, k, b;
    printf("Vnesi broj na bakterii:");
    scanf("%d", &n);
    printf("Na kolku minuti se delat?");
    scanf("%d", &i);
    printf("Na kolku minuti izumiraat?");
    scanf("%d", &j);
    printf("Kolkav procent umiraat?");
    scanf("%d", &x);
    printf("Vnesi minuti:");
    scanf("%d", &k);
    for(b = 1; b <= k; b++){
        if(b % i == 0)
            n *= 2;
        if(b % j == 0)
            n -= (n * (x / 100.0));
    }
    printf("Po %d minuti ke ima %d bakterii.\n", k, n);
    return 0;
}
