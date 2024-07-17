/*Напишете програма која од стандардниот влез зема 5 букви и ги испечатува по следниот редослед: прво петтата, па третата, па втората, па првата,
 * па четвртата буква. Пример:
vnesi pet bukvi
prva bukva: e
vtora bukva: i
treta bukva: b
chetvrta  bukva: n
petta bukva: p
Se dobi: pbien
*/
#include <stdio.h>

int main()
{
    char ch1, ch2, ch3, ch4, ch5;
    printf("Vnesi pet bukvi\n");
    scanf("%c %c %c %c %c", &ch1, &ch2, &ch3, &ch4, &ch5);
    printf("%c%c%c%c%c", ch5, ch3, ch2, ch1, ch4);
    return 0;
}
