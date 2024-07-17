/*Вие сте сопственик на продавница за компјутерска опрема. Треба да си направите апликација која ќе се грижи за хардверот што го имате на
 * располагање, количината на секој од деловите во продавницата и цените на деловите. Напишете програма која иницијализира датотека “hardware.dat”,
 * ви овозможува да внесете податоци за секој дел, да ги излистате податоците за специфичен дел, да дадете комплетен листинг на состојбата во вашата
 * продавница, да избришете податоци за даден дел ако тој веќе го немате на лагер, да ажурирате податоци за даден дел и да правите продажба. Под
 * продажба се подразбира намалување на бројот на потребни делови од датотеката, доколку има толку делови, колку што бара купецот. Да претпоставиме
 * дека имаме оптички читач на касата и дека секој дел се вчитува со негов код.

За започнување со работа, користете ги следните информации:
Код 	Име на дел	Количина	Цена
3	glusec Mico	7	10.34
56	monitor Kiki3	5	65.09
75	tastatura Biko8	4	12.09
89	matploc Ziko32	6	87.09
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILE_NAME "hardware.dat"

typedef struct {
    int kod;
    char imeNaDel[50];
    int kolicina;
    float cena;
} Hardware;

void inicijalizirajDatoteka();
void dodadiDel();
void izlistajDel();
void izlistajGiSiteDelovi();
void izbrisiDel();
void azurirajDel();
void prodaj();
void meni();

int main() {
    int izbor;
    inicijalizirajDatoteka();
    while (1) {
        meni();
        scanf("%d", &izbor);
        switch (izbor) {
        case 1:
            dodadiDel();
            break;
        case 2:
            izlistajDel();
            break;
        case 3:
            izlistajGiSiteDelovi();
            break;
        case 4:
            izbrisiDel();
            break;
        case 5:
            azurirajDel();
            break;
        case 6:
            prodaj();
            break;
        case 0:
            exit(0);
        default:
            printf("Izberi opcija od 0 do 6\n");
        }
    }

    return 0;
}

void inicijalizirajDatoteka(){
    FILE *file = fopen(FILE_NAME, "wb");
    if (!file) {
        exit(1);
    }
    Hardware delovi[] = {
        {3, "glusec Mico", 7, 10.34},
        {56, "monitor Kiki3", 5, 65.09},
        {75, "keyboard Biko8", 4, 12.09},
        {89, "matploc Ziko32", 6, 87.09}
    };

    fwrite(delovi, sizeof(Hardware), 4, file);
    fclose(file);
}

void dodadiDel(){
    FILE *file = fopen(FILE_NAME, "ab");
    if (!file) {
        return;
    }
    Hardware del;
    printf("Vnesi kod: ");
    scanf("%d", &del.kod);
    printf("Vnesi ime na del: ");
    scanf("%s", &del.imeNaDel);
    printf("Vnesi kolicina: ");
    scanf("%d", &del.kolicina);
    printf("Vnesi cena: ");
    scanf("%f", &del.cena);

    fwrite(&del, sizeof(Hardware), 1, file);
    fclose(file);
}

void izlistajDel(){
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        return;
    }
    int kod;
    printf("Vnesi kod: ");
    scanf("%d", &kod);
    Hardware del;
    int flag = 0;
    while (fread(&del, sizeof(Hardware), 1, file)) {
        if (del.kod == kod) {
            printf("Kod: %d, Ime na del: %s, Kolicina: %d, Cena: %.2f\n", del.kod, del.imeNaDel, del.kolicina, del.cena);
            flag = 1;
            break;
        }
    }
    if (!flag) {
        printf("Delot ne e pronajden.\n");
    }

    fclose(file);
}

void izlistajGiSiteDelovi(){
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        return;
    }
    Hardware del;
    printf("Kod\tIme na del\t\tKolicina\tCena\n");
    printf("------------------------------------------------------\n");
    while (fread(&del, sizeof(Hardware), 1, file)) {
        printf("%d\t%s\t\t%d\t\t%.2f\n", del.kod, del.imeNaDel, del.kolicina, del.cena);
    }

    fclose(file);
}

void izbrisiDel(){
    FILE *file = fopen(FILE_NAME, "rb");
    if (!file) {
        return;
    }
    int kod;
    printf("Vnesi kod: ");
    scanf("%d", &kod);

    FILE *tempFile = fopen("temp.dat", "wb");
    if (!tempFile) {
        fclose(file);
        return;
    }
    Hardware del;
    int flag = 0;
    while (fread(&del, sizeof(Hardware), 1, file)) {
        if (del.kod == kod) {
            flag = 1;
        } else {
            fwrite(&del, sizeof(Hardware), 1, tempFile);
        }
    }

    fclose(file);
    fclose(tempFile);

    if (flag) {
        remove(FILE_NAME);
        rename("temp.dat", FILE_NAME);
        printf("Uspesno e izbrisan delot.\n");
    } else {
        printf("Delot ne e pronajden.\n");
        remove("temp.dat");
    }
}

void azurirajDel(){
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        return;
    }
    int kod;
    printf("Vnesi kod: ");
    scanf("%d", &kod);

    Hardware del;
    int flag = 0;
    long pos;

    while ((pos = ftell(file)), fread(&del, sizeof(Hardware), 1, file)) {
        if (del.kod == kod) {
            flag = 1;
            printf("Vnesi ime: ");
            scanf("%s", del.imeNaDel);
            printf("Vnesi kolicina: ");
            scanf("%d", &del.kolicina);
            printf("Vnesi cena: ");
            scanf("%f", &del.cena);

            fseek(file, pos, SEEK_SET);
            fwrite(&del, sizeof(Hardware), 1, file);
            printf("Uspesno e azuriran delot.\n");
            break;
        }
    }

    if (!flag) {
        printf("Delot ne e pronajden.\n");
    }

    fclose(file);
}

void prodaj(){
    FILE *file = fopen(FILE_NAME, "rb+");
    if (!file) {
        return;
    }
    int kod, kolicina;
    printf("Vnesi kod: ");
    scanf("%d", &kod);
    printf("Vnesi kolicina: ");
    scanf("%d", &kolicina);
    Hardware del;
    int flag = 0;
    long pos;
    while ((pos = ftell(file)), fread(&del, sizeof(Hardware), 1, file)) {
        if (del.kod == kod) {
            flag = 1;
            if (del.kolicina >= kolicina) {
                del.kolicina -= kolicina;
                fseek(file, pos, SEEK_SET);
                fwrite(&del, sizeof(Hardware), 1, file);
                printf("Ostanata kolicina: %d\n", del.kolicina);
            } else {
                printf("Nema dovolno na zaliha.\n");
            }
            break;
        }
    }
    if (!flag) {
        printf("Delot ne e pronajden.\n");
    }

    fclose(file);
}

void meni() {
    printf("\nMeni:\n");
    printf("1 - Dodadi del\n");
    printf("2 - Izlistaj del\n");
    printf("3 - Izlistaj gi site delovi\n");
    printf("4 - Izbrisi del\n");
    printf("5 - Azuriraj del\n");
    printf("6 - Prodaj\n");
    printf("0 - Kraj\n");
}
