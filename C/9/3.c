/*Да се најде спротивен број на природниот број n. (Тоа е природниот број што ги има истите цифри со n, напишани во спротивен редослед.)*/
#include <stdio.h>

int sprotivenBroj(int n);

int main()
{
    int n;
    printf("Vnesi broj:");
    scanf("%d", &n);
    printf("Sprotiven broj na %d e %d", n, sprotivenBroj(n));
    return 0;
}

int sprotivenBroj(int n){
    int d, sprotiven = 0;

    while(n){
        d = n % 10;
        n /= 10;
        sprotiven = (sprotiven + d) * 10;
    }
    return sprotiven / 10;
}
