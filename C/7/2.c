/*Напиши програма која на функцијата vreme и доделува три целобројни аргументи, час, минута и секунда и како резултат го враќа бројот на секунди
 * до 12 часот. Имено, ако е 11 часот 59 минути и 58 секунди, тогаш има уште 2 секунди до 12 часот.*/
#include <stdio.h>

int vreme(int h, int m, int s);
int main()
{
    int h, m, s;

    printf("h:");
    scanf("%d", &h);
    printf("m:");
    scanf("%d", &m);
    printf("s:");
    scanf("%d", &s);

    printf("Preostanuvaat uste %d sekundi.\n", vreme(h, m, s));

    return 0;
}

int vreme(int h, int m, int s){
    int seconds = 60 * 60 * 12;
    seconds -= h * 60 * 60;
    seconds -= m * 60;
    seconds -= s;
    return seconds;
}
