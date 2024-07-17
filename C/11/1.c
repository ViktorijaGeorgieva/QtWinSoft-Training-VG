/*Напиши програм кој внесува телефонски број како стринг во облик (333) 333-3333. Програмот треба со користење на наредбата strtok да го извлече кодот
 * на државата како едно делче, а потоа да го спои целиот телефонски број во друг стринг без -. Програмот треба да го конвертира бројот на државата во
 * int, а седмоцифрениот телефонски број во long. Двата бројат треба да бидат испечатени.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char telefonskiBroj[14], *kodNaDrzavataStr, *telefonskiBrojStr, formatiranTelefonskiBroj[10] = "";
    int kodNaDrzavataInt;
    long telefonskiBrojLong;
    printf("Vnesi telefonski broj vo oblik (333) 333-3333:\n");
    fgets(telefonskiBroj, sizeof(telefonskiBroj), stdin);
    size_t len = strlen(telefonskiBroj);
    if(len > 0 && telefonskiBroj[len - 1] == '\n'){
        telefonskiBroj[len - 1] = '\0';
    }
    kodNaDrzavataStr = strtok(telefonskiBroj, " ()");
    kodNaDrzavataInt = atoi(kodNaDrzavataStr);
    telefonskiBrojStr = strtok(NULL, " -");
    strcat(formatiranTelefonskiBroj, telefonskiBrojStr);
    telefonskiBrojStr = strtok(NULL, " -");
    strcat(formatiranTelefonskiBroj, telefonskiBrojStr);
    telefonskiBrojLong = atol(formatiranTelefonskiBroj);
    printf("Kod na drzavata: %d\n", kodNaDrzavataInt);
    printf("Telefonski broj: %ld\n", telefonskiBrojLong);
    return 0;
}
