/*Напиши програма која на функцијата obratno и доделува цел број. Оваа функција го враќа бројот напишан со обратни цифри, т.е. ако сме ја повикале
 *  функцијата со параметарот 1243, треба да врати 3421.*/
#include <stdio.h>

int obratno(int num);

int main()
{
    int num;
    printf("Vnesi cel broj:");
    scanf("%d", &num);
    printf("Brojot %d vo obraten redosled e %d\n", num, obratno(num));

    return 0;
}

int obratno(int num){
    int d, reverse = 0;

    while(num){
        d = num % 10;
        num /= 10;
        reverse = (reverse + d) * 10;
    }

    return reverse/10;
}
