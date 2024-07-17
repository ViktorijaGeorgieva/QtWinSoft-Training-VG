/*Напиши програм кој чита датум во обликот 14/06/2005 и враќа датум во обликот 14 juni 2005. Корисникот да има можност да внесува колку што сака
 * датуми кои треба да бидат конвертирани во другиот излез.*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const char* konvertirajMesec(int mesec) {
    const char* meseci[] = {
        "Januari", "Fevruari", "Mart", "April", "Maj", "Juni", "Juli", "Avgust", "Septemvri", "Oktomvri", "Noemvri", "Dekemvri"
    };
    return meseci[mesec - 1];
}

int main() {
    char izbor, datum[11];
    int den, mesec, godina;

    do {
        printf("Vnesi datum vo oblik 14/06/2005: \n");
        fgets(datum, sizeof(datum), stdin);

        size_t len = strlen(datum);
        if (len > 0 && datum[len - 1] == '\n') {
            datum[len - 1] = '\0';
        }

        sscanf(datum, "%d/%d/%d", &den, &mesec, &godina);

        printf("%d %s %d\n", den, konvertirajMesec(mesec), godina);

        printf("Vnesi datum vo oblik 14/06/2005: \n");
        izbor = getchar();
        getchar();
    }while(izbor == 'da' || izbor == 'DA' || izbor == 'Da');

    return 0;
}
